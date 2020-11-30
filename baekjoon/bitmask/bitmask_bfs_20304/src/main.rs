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

fn bfs(start: u32, n: u32, dest: &Vec<u32>) -> u32{
    let mut depth = 0;
    let mut queue = VecDeque::new();

    queue.push_back((start, 0));

    while let Some((b, d)) = queue.pop_front() {
        let mut cur = 1;
        //println!("{}", d);
        if dest.contains(&b) {
            depth = d;
            break;
        }
        while cur <= n {
            let flipped = b ^ cur;
            if flipped <= n {
                queue.push_back((flipped,d+1));
            }
            cur = cur << 1;
        }
    }
    depth
}
fn main() {
    let mut s = String::new();

    stdin().read_to_string(&mut s).expect("read error");

    let mut iter = s.split_whitespace();

    let n : u32 = iter.read();
    let m : u32 = iter.read();

    let v : Vec<u32> = iter.read_collect();
    let mut ans = 0;
    for i in 1..(n+1) {
        if v.contains(&i) {
            continue;
        }
        ans = max(ans, bfs(i,n, &v));
    }
    println!("{}", ans);
}
