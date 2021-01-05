use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::cmp::min;
use std::io::{stdin, Read};

trait Parser {
    fn read<T,E>(&mut self) -> T where T : FromStr<Err = E>,
                                       E : Debug;
    fn read_vec<T,E>(&mut self, n: usize) -> Vec<T> where T : FromStr<Err = E>,
                                                          E : Debug;
}

impl<'a> Parser for SplitWhitespace<'a>{
    fn read<T, E>(&mut self) -> T where T: FromStr<Err=E>,
                                        E: Debug {
        self.next().expect("EOF").parse().expect("Parse error")
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

    let n = iter.read();
    let mut dp: Vec<usize> = vec![0; n];
    dp[0] = 1;
    for i in 0..n {
        let cur : usize = iter.read();
        if cur == 0 || dp[i] == 0{
            continue;
        }
        for j in 1..(cur+1) {
            if i + j >= dp.len() { break; }
            if dp[i+j] == 0 || dp[i+j] > dp[i] + 1 {
                dp[i + j] =  dp[i] + 1;
            }
        }
    }
    println!("{}", dp[n - 1] as isize - 1);
}