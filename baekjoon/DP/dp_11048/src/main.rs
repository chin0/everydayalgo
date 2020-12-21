use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::cmp::max;
use std::io::{stdin, Read};

trait Parser {
    fn read<T, E>(&mut self) -> T where T: FromStr<Err=E>,
                                        E: Debug;
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T, E>(&mut self) -> T where T: FromStr<Err=E>,
                                        E: Debug {
        self.next().expect("EOF").parse().expect("Parse error")
    }
}

// 1,1은 고려할 필요가 없다. 왜냐면 1,0, 0,1을 거치거나 0,1, 1,0을 거치면 되기 때문에 무조건 1,1을 고르는것보단 더 나은 경우가 있음.

fn main() {
    let mut s = String::new();
    stdin().read_to_string(&mut s).expect("Read error");
    let mut iter = s.split_whitespace();

    let (n,m) : (usize,usize) = (iter.read(), iter.read());
    let mut map : Vec<Vec<u32>> = Vec::new();

    for _ in 0..n {
        let mut temp = Vec::new();
        for _ in 0..m {
            temp.push(iter.read());
        }
        map.push(temp);
    }
    let mut dp = vec![vec![0u32;m+1];n+1];

    for i in 1..(n+1) {
        for j in 1..(m+1) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + map[i-1][j-1];
        }
    }
    println!("{}", dp[n][m]);
}
