use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::io::{stdin, Read};
use std::cmp::max;
use std::mem::transmute;
use crate::direction::{UP, LEFT, RIGHT};

trait Parser {
    fn read<T,E>(&mut self) -> T
        where T: FromStr<Err = E>,
              E : Debug;
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T, E>(&mut self) -> T where T: FromStr<Err=E>,
                                        E: Debug {
        self.next().expect("EOF").parse().expect("parse error")
    }
}

#[derive(Copy, Clone)]
enum direction {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
}

fn merge_line(v: &mut Vec<Vec<u16>>, idx: usize, d: direction){
    let mut i = 0;
    let mut j = i+1;
    let mut m = 0;
    let len = v.len();
    let mut copy: Vec<u16>;
    match d {
        direction::UP => {
            copy = v.iter().map(|x| x[idx]).collect()
        },
        direction::DOWN => {
            copy = v.iter().rev().map(|x| x[idx]).collect();
        },
        direction::LEFT => {
            copy = v[i].iter().map(|x| *x).collect();
        },
        direction::RIGHT => {
            copy = v[i].iter().rev().map(|x| * x).collect();
        }
    }
    while i < copy.len() && j < copy.len() {
        if i == j {
            j += 1;
            continue
        }
        if copy[j] != 0 {
            if copy[i] == copy[j] {
                copy[i] += copy[j];
                copy[j] = 0;
                i += 1;
                j += 1;
            } else if copy[i] == 0 {
                copy[i] = copy[j];
                copy[j] = 0;
                j += 1;
            } else {
                i+= 1;
            }
        } else {
            j += 1;
        }
    }
    match d {
        direction::UP => {
            for i in 0..v.len() {
                v[i][idx] = copy[i];
            }
        },
        direction::DOWN => {
            for i in 0..v.len() {
                v[(len -1 ) - i][idx] = copy[i];
            }
        },
        direction::LEFT => {
            for i in 0..v.len() {
                v[idx][i] = copy[i];
            }
        },
        direction::RIGHT => {
            for i in 0..v.len() {
                v[idx][(len-1) - i] = copy[i];
            }
        }
    }
}

fn permutation(v: &mut Vec<Vec<u16>>, d: direction) {
    for i in 0..v.len() {
        merge_line(v, i, d);
    }
}

fn search(v: &mut Vec<Vec<u16>>, n: u8) -> u16{
    if n == 5 {
        let mut m = 0;
        for i in v {
            for j in i {
                m = max(m,*j);
            }
        }
        m
    } else {
        let mut m = 0;
        for i in 0..4 {
            let temp = v.clone();
            permutation(v, unsafe{transmute(i as i8) });
            m = max(search(v, n + 1),m);
            v.clone_from_slice(&temp[..]);
        }
        m
    }
}
fn main() {
    let mut s = String::new();

    stdin().read_to_string(&mut s).expect("read error");
    let mut iter = s.split_whitespace();

    let n : u32 = iter.read();
    let mut v = Vec::new();
    for i in 0..n {
        let mut temp = Vec::new();
        for i in 0..n {
            temp.push(iter.read());
        }
        v.push(temp);
    }
    println!("{}", search(&mut v,0));
}
