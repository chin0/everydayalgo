use std::str::{FromStr, SplitWhitespace};
use std::collections::BinaryHeap;
use std::fmt::Debug;
use std::io::{stdin,stdout, Read, BufWriter, Write};
use std::cmp::Reverse;

trait Parser {
    fn read<T,E>(&mut self) -> T where T : FromStr<Err = E>,
                                       E : Debug;
    fn read_vec<T,E>(&mut self, n: usize) -> Vec<T> where T: FromStr<Err = E>,
                                                          E: Debug;
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
    let stdout = stdout();
    let mut out = BufWriter::new(stdout.lock());
    stdin().read_to_string(&mut s).expect("read error");
    let mut iter = s.split_whitespace();

    let n : u32 = iter.read();
    let mut leftheap = BinaryHeap::new(); //maxheap
    let mut rightheap = BinaryHeap::new();
    let mut mid : i32 = iter.read();
    writeln!(out,"{}", mid);
    for _ in 0..(n-1) {
        let current_value : i32 = iter.read();
        if current_value <= mid {
            leftheap.push(current_value);
        }
        if current_value > mid {
            rightheap.push(Reverse(current_value));
        }
        if leftheap.len() > rightheap.len() {
            if let Some(data) = leftheap.pop() {
                rightheap.push(Reverse(mid));
                mid = data;
            }
        } else if rightheap.len() > leftheap.len()+1 {
            if let Some(Reverse(data)) = rightheap.pop() {
                leftheap.push(mid);
                mid = data;
            }
        }
        writeln!(out,"{}", mid);
    }
}
