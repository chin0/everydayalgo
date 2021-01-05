use std::cmp::{Ordering, Reverse, max};
use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::io::{stdin, stdout, Read, BufWriter, Write};
use std::collections::BinaryHeap;

trait Parser {
    fn read<T,E>(&mut self) -> T where T : FromStr<Err = E>,
                                       E : Debug;
    fn read_vec<T,E>(&mut self, n: usize) -> Vec<T> where T: FromStr<Err = E>,
                                                          E: Debug;
}


struct Graph {
    n : usize, //number of vertices
    items: Vec<u32>,
    adj_list: Vec<Vec<(usize, u32)>>, //adj list (node id, weight)
}

impl Graph {
    fn new(n: usize, items: Vec<u32>) -> Self {
        let adj_list = vec![vec![];n];
        Graph {
            n,
            items,
            adj_list
        }
    }

    fn add_edge(&mut self, s:usize, e:usize, w: u32) {
        self.adj_list[s].push((e,w));
    }

    fn add_undirected_edge(&mut self, s: usize, e: usize, w: u32) {
        self.add_edge(s,e,w);
        self.add_edge(e,s,w);
    }

    fn dijkstra(&mut self, start: usize) -> Vec<u32> {
        let mut visited = vec![false; self.n];
        let mut heap = BinaryHeap::new();
        let mut dist = vec![u32::max_value(); self.n];
        dist[start] = 0;
        heap.push((Reverse(0),start));
        while let Some((Reverse(dist_u), u)) = heap.pop() {
            if !visited[u] {
                visited[u] = true;
                for &(i,w) in self.adj_list[u].iter() {
                    let dist_i = dist_u + w;
                    if dist[i] > dist_i {
                        dist[i] = dist_i;
                        heap.push((Reverse(dist_i),i));
                    }
                }
            }
        }
        dist
    }
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T, E>(&mut self) -> T where T: FromStr<Err=E>,
                                        E: Debug {
        self.next().expect("EOF").parse().expect("Parse error.")
    }
    fn read_vec<T, E>(&mut self, n: usize) -> Vec<T> where T: FromStr<Err=E>,
                                                           E: Debug {
        self.take(n).map(|x| x.parse().expect("parse error")).collect()
    }
}
fn main() {
    let mut s = String::new();
    stdin().read_to_string(&mut s).expect("read error");
    let mut iter = s.split_whitespace();

    let (n,m,r) = (iter.read(), iter.read(), iter.read());
    let items = iter.read_vec(n);
    let mut g = Graph::new(n, items);
    for _ in 0..r {
        let s : usize = iter.read();
        let e : usize = iter.read();
        let w = iter.read();
        g.add_undirected_edge(s-1,e-1,w);
    }
    let mut ans = 0;
    for i in 0..n {
        let cur_ans = g.dijkstra(i).into_iter()
            .enumerate()
            .filter(|(idx,val)| *val <= m)
            .map(|x| g.items[x.0]).sum();
        ans = max(ans,cur_ans);
    }
    println!("{}",ans);
}
