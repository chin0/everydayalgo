use std::str::{FromStr,SplitWhitespace};
use std::fmt::{Debug, Error};
use std::io::{stdin, Read};
use std::cmp::min;

trait Parser {
    fn read<T,E>(&mut self) -> T
        where T: FromStr<Err = E>,
              E:Debug;
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T,E>(&mut self) -> T
        where T: FromStr<Err=E>,
              E: Debug {
        self.next().expect("EOF")
            .parse::<T>().expect("Parse Error")
    }
}

fn count(x: usize, n: usize) -> usize {
    let mut ans = 0;

    for i in 1..(n+1) {
        ans += min(x/i , n);
    }
    ans
}
fn main() {
    let mut s = String::new();
    stdin().read_to_string(&mut s).expect("fuck");

    let mut iter = s.split_whitespace();

    let n : usize = iter.read();
    let k : usize = iter.read();

    let mut min = 1;
    let mut max = k;
    let mut ans = None;

    while min<= max {
        let mid = (min + max) / 2;
        if count(mid, n) < k {
            min = mid+1;
        } else {
            ans = Some(mid);
            max = mid - 1;
        }
    }
    if let Some(ans) = ans {
        println!("{}" ,ans);
    }
}
