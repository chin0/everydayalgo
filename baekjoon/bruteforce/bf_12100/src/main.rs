use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::io::{stdin, Read};
use std::cmp::max;

trait Parser {
    fn read<T,E>(&mut self) -> T
        where T: FromStr<Err = E>,
              E : Debug;
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T, E>(&mut self) -> T where T: FromStr<Err=E>,
                                        E: Debug {
        self.next().expect("EOF").parse().expect("parse error")
    }
}

fn merge_line(mut v: Vec<u16>) -> (Vec<u16>, u16) {
    let mut i = 0;
    let mut j = i+1;
    let mut m = 0;
    while i < v.len() && j < v.len() {
        if v[j] != 0 {
            if v[i] == v[j] {
                v[i] += v[j];
                v[j] = 0;
                i += 1;
                j += 1;
            } else if v[i] == 0 {
                v[i] = v[j];
                v[j] = 0;
                j += 1;
            } else {
                i+= 1;
            }
        } else {
            j += 1;
        }
    }
    return (v, 0)
}
fn main() {
    /*
    let mut s = String::new();

    stdin().read_to_string(&mut s).expect("read error");
    let mut iter = s.split_whitespace();

     */
    println!("{:?}", merge_line(vec![2,0,2,4,4]));
    println!("{:?}", merge_line(vec![2,0,2,4,8]));
    println!("{:?}", merge_line(vec![2,2,4,4,8]));
}
