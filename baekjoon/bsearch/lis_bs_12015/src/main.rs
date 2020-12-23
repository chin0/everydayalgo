use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::io::{stdin, Read};

trait Parser {
    fn read<T,E>(&mut self) -> T where T: FromStr<Err = E>,
                                       E: Debug;
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T, E>(&mut self) -> T where T: FromStr<Err=E>,
                                        E: Debug {
        self.next().expect("EOF").parse().expect("parse error")
    }
}

//find lower bound on ordered list.
fn lower_bound<T: Ord>(m: &[T], val: T)  -> usize {
    let mut lo = 0;
    let mut hi = m.len();
    while lo < hi {
        let mid = (lo+hi)/2;
        if m[mid] >= val {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    hi
}
fn main() {
    let mut s = String::new();

    stdin().read_to_string(&mut s).expect("read error");
    let mut iter = s.split_whitespace();

    let n : u32 = iter.read();
    let mut lis = Vec::new();
    lis.push(-1);
    for _ in 0..n {
        let cur = iter.read();
        if lis[lis.len()-1] < cur {
            lis.push(cur);
        } else {
            let l = lower_bound(&lis[..], cur);
            lis[l] = cur;
        }
    }
    println!("{}", lis.len()-1);
}
