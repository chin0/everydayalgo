use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::io::{stdin, Read};
use std::cmp::max;

trait Parser {
    fn read<T,E>(&mut self) -> T
        where T: FromStr<Err = E>,
              E: Debug;
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T,E>(&mut self) -> T
        where T: FromStr<Err = E>,
              E: Debug
    {
        self.next().expect("EOF").parse().expect("parse error")
    }
}
fn main() {
    let mut s = String::new();
    stdin().read_to_string(&mut s).expect("Failed to read.");
    let mut iter = s.split_whitespace();

    let t : u32= iter.read();

    for _ in 0..t {
        let mut v : Vec<i32> = Vec::new();
        let n : usize = iter.read();
        for _ in 0..n {
            v.push(iter.read());
        }
        v.sort();
        let v : Vec<&i32> = v.iter().step_by(2)
            .chain(v.iter()
                          .skip(1)
                          .step_by(2).rev())
            .collect();
        let mut m = 0;
        for i in 1..n {
            m = max(m, (v[i] - v[i-1]).abs());
        }
        println!("{}", m);
    }
}
