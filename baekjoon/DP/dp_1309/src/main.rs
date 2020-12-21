use std::{fmt::Debug, str::{FromStr, SplitWhitespace}};
use std::io::Read;

trait Parser {
    fn read<T,E>(&mut self) -> T
        where T : FromStr<Err = E>,
              E : Debug;
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T,E>(&mut self) -> T 
        where T : FromStr<Err = E>,
              E : Debug
    {
        self.next().expect("EOF").parse().expect("Parse Error")
    }
}
fn main() {
    let mut dp = [0u32;100001];
    let mut s = String::new();

    std::io::stdin().read_to_string(&mut s).expect("read error");

    let mut iter = s.split_whitespace();
    let n : usize= iter.read();
    dp[0] = 1; //빈칸도 1개로 카운트 하므로.
    dp[1] = 3;
    for i in 2..(n+1) {
        dp[i]= (2 * dp[i-1] + dp[i-2]) % 9901;
    }
    println!("{}", dp[n]);
}
