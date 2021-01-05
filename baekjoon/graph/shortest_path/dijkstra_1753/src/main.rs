use std::cmp::{Ordering, Reverse};
use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::io::{stdin, stdout, Read, BufWriter, Write};

struct Graph {
    n : usize, //number of vertices
    adj_list: Vec<Vec<(usize, u32)>>, //adj list (node id, weight)
}

impl Graph {
    fn new(n: usize) -> Self {
        let adj_list = vec![vec![];n];
        Graph {
            n,
            adj_list
        }
    }

    fn add_edge(&mut self, s: usize, e: usize, w: u32) {
        self.adj_list[s].push((e,w));
    }

    fn add_undirected_edge(&mut self, s: usize, e: usize, w: u32) {
        self.add_edge(s,e,w);
        self.add_edge(e,s,w);
    }

    fn dijkstra(&mut self, start: usize) -> Vec<u32> {
        let mut visited = vec![false; self.n];
        let mut heap = std::collections::BinaryHeap::new();
        let mut dist = vec![u32::max_value(); self.n];
        dist[start] = 0;
        heap.push((Reverse(0),start));
        while let Some((Reverse(dist_u),u)) = heap.pop() {
            if !visited[u] {
                visited[u] = true;
                for &(i, w) in self.adj_list[u].iter() {
                    let dist_i = dist_u + w;
                    if dist[i] > dist_i {
                        dist[i] = dist_i;
                        heap.push((Reverse(dist_i), i));
                    }
                }
            }
        }
        dist
    }
}

trait Parser {
    fn read<T,E>(&mut self) -> T where T : FromStr<Err = E>,
                                       E : Debug;
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T, E>(&mut self) -> T where T: FromStr<Err=E>,
                                        E: Debug {
        self.next().expect("EOF").parse().expect("Parse error.")
    }
}

fn main() {
    let mut s = String::new();
    let stdout = stdout();
    let mut out = BufWriter::new(stdout.lock());
    stdin().read_to_string(&mut s).expect("read error");
    let mut iter = s.split_whitespace();

    let v = iter.read();
    let e = iter.read();
    let k: usize = iter.read();
    let mut g = Graph::new(v);

    for i in 0..e {
        let (s,e,w):(usize,usize,u32) = (iter.read(), iter.read(), iter.read());
        g.add_edge(s-1,e-1,w);
    }

    let d = g.dijkstra(k-1);
    for i in d {
        if i==u32::max_value() {
            writeln!(out,"INF");
        }
        else {
            writeln!(out,"{}", i);
        }
    }
}
