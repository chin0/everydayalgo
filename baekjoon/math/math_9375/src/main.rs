use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::collections::HashMap;
use std::io::{stdin, Read};

trait Parser {
    fn read<T,E>(&mut self) -> T
        where T: FromStr<Err = E>, E: Debug;
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T,E>(&mut self) -> T
        where T: FromStr<Err = E>,
              E: Debug
    {
        self.next().expect("EOF").parse().expect("Failed Parse")
    }
}

fn main() {
    let mut input = String::new();

    stdin().read_to_string(&mut input).expect("failed to read");
    let mut iter = input.split_whitespace();

    let t : u32 = iter.read();
    for _ in 0..t {
        let n: u32 = iter.read();
        let mut h: HashMap<String, usize> = HashMap::new();

        for _ in 0..n {
            let (_, category): (String, String) = (iter.read(), iter.read());
            if let Some(data) = h.get(&category) {
                h.insert(category, data + 1);
            } else {
                h.insert(category, 1);
            }
        }
        let v : Vec<&usize> = h.values().collect();
        let nk = h.len();
        let mut ans = 0;
        for i in 0..v.len() {
            let mut cur = 1;
            for j in 0..nk {
                cur *= v[(i + j) % v.len()];
            }
            println!("{}", cur);
            ans += cur;
        }
        println!("{}", ans);
    }
}
