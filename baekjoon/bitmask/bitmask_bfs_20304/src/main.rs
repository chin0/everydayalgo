use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::io::{stdin, Read};
use std::iter::FromIterator;
use std::collections::VecDeque;
use std::cmp::{min, max};

trait Parser {
    fn read<T,E>(&mut self) -> T
        where T: FromStr<Err = E>,
              E: Debug;

    fn read_collect<T,U,E>(&mut self) -> T
        where T: FromIterator<U>,
              U: FromStr<Err = E>,
              E: Debug;
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T, E>(&mut self) -> T where T: FromStr<Err=E>,
                                        E: Debug {
        self.next().expect("EOF").parse().expect("parse error")
    }

    fn read_collect<T,U,E>(&mut self) -> T  where T: FromIterator<U>,
                                                  U: FromStr<Err=E>,
                                                  E: Debug {
        self.map(|x| x.parse().expect("parse error")).collect()
    }
}

//multi start bfs!
fn bfs(start: &Vec<u32>, n: u32) -> u32{
    let mut last = 0;
    let mut queue = VecDeque::new();

    start.iter().for_each(|x| {
        queue.push_back((*x, 0));
    });

    let mut visited = vec![false; n as usize +1];
    while let Some((b, d)) = queue.pop_front() {
        last = d;
        let mut cur = 1;
        while cur <= n {
            let flipped = b ^ cur;
            if flipped <= n  && !visited[flipped as usize]{
                //println!("{} {} {}", flipped as usize, cur, visited[flipped as usize]);
                visited[flipped as usize] = true;
                queue.push_back((flipped,d+1));
            }
            cur = cur << 1;
        }
    }
    last
}

fn main() {
    let mut s = String::new();

    stdin().read_to_string(&mut s).expect("read error");

    let mut iter = s.split_whitespace();

    let n : u32 = iter.read();
    let m : u32 = iter.read();

    let v : Vec<u32> = iter.read_collect();
    println!("{}",bfs(&v,n));
}
