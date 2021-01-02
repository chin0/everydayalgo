use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::io::{stdin, Read};

trait Parser {
    fn read<T,E>(&mut self) -> T where T : FromStr<Err = E>,
                                       E : Debug;
    fn read_vec<T,E>(&mut self, n: usize) -> Vec<T> where T: FromStr<Err = E>,
                                                E: Debug;
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T, E>(&mut self) -> T where T: FromStr<Err=E>,
                                        E: Debug {
        self.next().expect("EOF").parse().expect("Parse error")
    }

    fn read_vec<T, E>(&mut self, n: usize) -> Vec<T> where T: FromStr<Err=E>,
                                                 E: Debug {
        self.take(n).map(|x| x.parse().expect("parse error")).collect()
    }
}

fn lower_bound<T: Ord>(arr: &[T], val: T) -> usize {
    let mut lo = 0;
    let mut high = arr.len();
    while lo < high {
        let mid = (lo + high) / 2;
        if arr[mid] >= val {
            high = mid;
        } else {
            lo = mid+1;
        }
    }
    high
}
fn upper_bound<T: Ord>(arr: &[T], val: T) -> usize {
    let mut lo = 0;
    let mut high = arr.len();
    while lo < high {
        let mid = (lo + high) / 2;
        if arr[mid] <= val {
            lo = mid+1;
        } else {
            high = mid;
        }
    }
    high
}
fn main() {
    let mut s = String::new();
    stdin().read_to_string(&mut s).expect("read error");
    let mut iter = s.split_whitespace();

    let n = iter.read();
    let mut a: Vec<i32> = Vec::new();
    let mut b: Vec<i32> = Vec::new();
    let mut c : Vec<i32>= Vec::new();
    let mut d: Vec<i32> = Vec::new();
    for _ in 0..n {
        a.push(iter.read());
        b.push(iter.read());
        c.push(iter.read());
        d.push(iter.read());
    }
    let mut sum1 = Vec::new();
    for i in &a {
        for j in &b {
            sum1.push(i + j);
        }
    }
    sum1.sort();
    let mut sum2 = Vec::new();
    for i in &c {
        for j in &d {
            sum2.push(i + j);
        }
    }
    sum2.sort();
    let mut ans = 0;
    for i in &sum1 {
        let data = lower_bound(&sum2[..], -*i);
        let data2 = upper_bound(&sum2[..], -*i);
        if  data < sum2.len() && -*i == sum2[data] {
            ans += data2 - data;
        }
    }
    println!("{}", ans);
}
