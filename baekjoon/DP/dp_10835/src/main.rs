use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::cmp::max;
use std::io::{stdin, Read};

trait Parser {
    fn read<T,E>(&mut self) -> T where T : FromStr<Err = E>,
                                       E : Debug;
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T, E>(&mut self) -> T where T: FromStr<Err=E>,
                                        E: Debug {
        self.next().expect("EOF").parse().expect("parse error")
    }
}
fn solve(n: usize, m: usize, left: &Vec<usize>, right: &Vec<usize>, dp: &mut Vec<Vec<isize>>) -> isize{
    if n == left.len() - 1 || m == right.len() - 1{
        let mut result = 0;
        for i in m..right.len() {
            if left[n] > right[i] { result += right[i];}
            else { break; }
        }
        return result as isize;
    }

    if dp[n][m] != -1{
        return dp[n][m];
    }

    let mut d = max(solve(n+1,m,left,right,dp), solve(n+1,m+1,left,right,dp));
    if left[n] > right[m] {
        d = max(d, solve(n,m+1, left,right,dp) + right[m] as isize);
    }
    dp[n][m] = d;
    return d
}
fn main() {
    let mut s = String::new();
    stdin().read_to_string(&mut s).expect("read error");
    let mut iter = s.split_whitespace();

    let n = iter.read();
    let mut dp = vec![vec![-1;n];n];
    let mut left = Vec::new();
    let mut right = Vec::new();

    for _ in 0..n {
        left.push(iter.read());
    }
    for _ in 0..n {
        right.push(iter.read());
    }

    println!("{}", solve(0,0, &left, &right, &mut dp));
}
