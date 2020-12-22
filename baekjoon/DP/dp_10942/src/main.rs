use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::io::{stdin, Read, BufWriter,Write,stdout};

trait Parser {
    fn read<T,E>(&mut self) -> T where T: FromStr<Err = E>,
                                       E: Debug;
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T, E>(&mut self) -> T where T: FromStr<Err=E>,
                                        E: Debug {
        self.next().expect("EOF").parse().expect("EOF")
    }
}

fn main() {
    let mut s = String::new();
    stdin().read_to_string(&mut s).expect("read error");
    let mut iter = s.split_whitespace();
    let stdout = std::io::stdout();
    let mut out = BufWriter::new(stdout.lock());

    let n = iter.read();
    let mut seq = vec![0;n];
    let mut dp = vec![vec![false; n]; n];
    for i in 0..n {
        seq[i] = iter.read();
        dp[i][i] = true;
    }

    for len in 1..n {
        for i in 0..(n-len) {
            if len == 1 {
                dp[i][i+len] = seq[i] == seq[i+len];
            }
            else if seq[i] == seq[i + len] {
                dp[i][i+len] = dp[i+1][i+len-1];
            }
        }
    }
    let m = iter.read();
    for _ in 0..m {
        let (s,e) : (usize,usize) = (iter.read(), iter.read());
        writeln!(out,"{}", dp[s-1][e-1] as u32).unwrap();
    }
}