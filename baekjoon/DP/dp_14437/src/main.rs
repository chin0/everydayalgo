use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::io::{stdin, Read};
use std::cmp::min;

trait Parser {
    fn read<T,E>(&mut self) -> T where T: FromStr<Err = E>,
                                       E: Debug;
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T, E>(&mut self) -> T where T: FromStr<Err=E>,
                                        E: Debug {
        self.next().expect("EOF").parse().expect("Parse error")
    }
}

/*
fn solve(n: usize, k: usize, dp: &mut Vec<Vec<Option<usize>>>) -> usize {
    if k == 1 {
        return k;
    }
    if let Some(value) = dp[n][k] {
        value
    } else {
        let mut value = 0;
        for i in 0..min(26, n+1) {
            value = (value + solve(n-i,k-1,dp)) % 1000000007;
        }
        dp[n][k] = Some(value);
        value
    }
}
 */
fn main() {
    let mut s = String::new();
    stdin().read_to_string(&mut s).expect("read error");
    let mut iter = s.split_whitespace();

    let n : usize = iter.read();
    let s : String = iter.read();
    let k = s.len();
    let mut dp = vec![vec![0u32; 3001]; 3001];
    for i in 0..(k+1) {
        dp[i][0] = 1;
    }
    for i in 0..26 {
        dp[1][i] = 1;
    }

    //dp[i][k] = dp[i][k-1] + dp[i-1][k]
    //그리고 i >= 26이면 dp[i][k] = dp[i][k-1] + dp[i-1][k] - dp[i-25][k-1]
    for i in 2..(k+1) {
        for j in 1..(n+1) {
            if j >= 26 {
                // 모듈러 뺄샘이라서 mod 더해줘야함!!(음수로 바
                dp[i][j] = ((dp[i][j-1] + dp[i-1][j]) % 1000000007 - dp[i-1][j-26] + 1000000007) % 1000000007;
            } else {
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 1000000007
            }
        }
    }
    println!("{}", dp[k][n]);
}
