#[allow(unused_imports)]

use std::io::{BufWriter, stdin, stdout, Write};
use std::cmp::max;

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}

impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed Parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}
fn main() {
    let mut a = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let (w, h) : (i32, i32) = (a.next(), a.next());
    let n = a.next::<i32>();
    let mut xlist: Vec<i32> = vec![0,h];
    let mut ylist: Vec<i32> = vec![0,w];

    for i in 0..n {
        if a.next::<i32>() == 0 {
            xlist.push(a.next());
        } else {
            ylist.push(a.next());
        }
    }
    xlist.sort();
    ylist.sort();

    let mut xdiff = 0;
    let mut ydiff = 0;
    for i in 1..xlist.len() {
        xdiff = max(xdiff,xlist[i] - xlist[i-1]);
    }
    for i in 1..ylist.len() {
        ydiff = max(ydiff,ylist[i] - ylist[i-1]);
    }
    println!("{:?}", xdiff * ydiff);
}
