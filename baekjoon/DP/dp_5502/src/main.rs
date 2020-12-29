use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::io::{stdin, Read};
use std::cmp::min;

trait Parser {
    fn read<T,E>(&mut self) -> T where T : FromStr<Err = E>,
                                       E : Debug;
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T, E>(&mut self) -> T where T: FromStr<Err=E>,
                                        E: Debug {
        self.next().expect("EOF").parse().expect("Parse Error")
    }
}
fn main() {
    let mut s = String::new();

    stdin().read_to_string(&mut s).expect("read error");
    let mut iter = s.split_whitespace();
    let n = iter.read();
    let s : String = iter.read();
    let s = s.as_bytes();

    let mut dp = vec![vec![0;n];n];

    for i in 0..n {
        dp[i][i] = 0;
    }

    for i in 0..n-1 {
        if s[i] == s[i+1] { dp[i][i+1] = 0; }
        else { dp[i][i+1] = 1; }
    }

    for i in 2..n {
        for j in 0..(n-i) {
            if s[j] == s[j+i] { dp[j][j+i] = dp[j+1][j+i-1]; }
            else { dp[j][j+i] =min(1 + dp[j+1][j+i], 1 + dp[j][j+i-1]); }
        }
    }
    println!("{}", dp[0][n-1]);
}
