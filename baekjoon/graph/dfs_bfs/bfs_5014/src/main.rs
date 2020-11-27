use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::io::{stdin, Read};
use std::collections::VecDeque;

trait Parser {
    fn read<T,E>(&mut self) -> T
        where T: FromStr<Err=E>,
              E: Debug;
}

impl<'a> Parser for SplitWhitespace<'a> {
    fn read<T, E>(&mut self) -> T where T: FromStr<Err=E>,
                                        E: Debug {
        self.next().expect("EOF").parse().expect("Failed to parse")
    }
}
fn main() {
    let mut s = String::new();

    stdin().read_to_string(&mut s).expect("Failed to read");

    let mut iter = s.split_whitespace();
    let (f,mut s,g,u,d) : (i32,i32,i32,i32,i32)
        = (iter.read(), iter.read(), iter.read(), iter.read(), iter.read());

    let mut scnt = 0;
    if g - s >= 0  && u != 0{
        scnt = (g-s) / u;
        s = s + u * scnt;
    } else if s - g > 0 && d != 0{
        scnt = (s-g) / d;
        s = s - d * scnt;
    }
    //println!("{} {}",s,scnt);
    let mut q = VecDeque::new();
    let mut visited = vec![false; f as usize + 1];
    q.push_back((s,scnt));

    let mut ans = None;
    while let Some((current, cnt)) = q.pop_front() {
        visited[current as usize] = true;
        //println!("{} {}", current, cnt);
        if current == g {ans = Some(cnt);break;}
        let upnext = current + u;
        let downnext = current - d;
        if upnext <= f  && !visited[upnext as usize]{
            q.push_back((upnext, cnt+1));
        }
        if downnext >= 1 && !visited[downnext as usize]{
            q.push_back((downnext, cnt+1));
        }
    }
    if let Some(ans) = ans {
        println!("{}", ans);
    } else {
        println!("use the stairs");
    }
}
