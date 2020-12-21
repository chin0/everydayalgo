use std::str::{FromStr, SplitWhitespace};
use std::io::{stdin, Read};
use std::fmt::Debug;

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

fn solve(s: usize, e: usize, sum: &Vec<i32>, dp: &mut Vec<Vec<i32>>) -> i32 {
    if s==e {
        return 0;
    }
    if dp[s][e] != -1 {
        return dp[s][e];
    }
    for k in s..e {
        let temp = solve(s,k,sum, dp) + solve(k+1,e, sum,dp) + sum[e] - sum[s-1];
        let cur_memo = &mut dp[s][e];
        if *cur_memo == -1 || *cur_memo > temp {
            *cur_memo = temp;
        }
    }
    dp[s][e]
}
fn main() {
    let mut s = String::new();

    stdin().read_to_string(&mut s).expect("Failed to read.");
    let mut iter = s.split_whitespace();
    let t : u32= iter.read();

    for _ in 0..t {
        let n = iter.read();
        let mut v = vec![0; n+1];
        let mut dp = vec![vec![-1;n+1];n+1];

        for i in 1..(n+1) {
            v[i] = iter.read();
            v[i] += v[i-1];
        }
        println!("{}", solve(1,n,&v,&mut dp));
    }
}
