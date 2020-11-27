use std::str::{FromStr, SplitWhitespace};
use std::fmt::Debug;
use std::collections::VecDeque;
use std::io::{stdin, Read};
use std::cmp::{max, min};


//어떤 특정 (x,y)에서 벽을 부순 여부에 따라서 아예 다른 경로가 되는것을 아이디어로 한다.
trait Parser {
    fn read<T,E>(&mut self) -> T
        where T : FromStr<Err=E>,
              E : Debug;
}

impl<'a> Parser for SplitWhitespace<'a>
{
    fn read<T,E>(&mut self) -> T
        where T: FromStr<Err=E>,
              E: Debug
    {
        self.next().expect("EOF").parse().expect("failed to parse.")
    }
}

struct BFS<'a> {
    m : usize,
    n : usize,
    map: &'a Vec<Vec<bool>>
}

impl<'a> BFS<'a> {
    fn new(map: &'a Vec<Vec<bool>>) -> Self {
        let m = map[0].len();
        let n = map.len();
        BFS {m, n, map}
    }

    fn check(&self, x: i32, y: i32) -> bool{
        x >= 0 && y >= 0 && x < self.m as i32 && y < self.n as i32
    }

    fn solve(&'a self) -> i32 {
        let d = [(0,1),(0,-1), (1,0), (-1,0)];
        let mut visited = vec![vec![vec![-1; 2]; self.m]; self.n];

        let mut q = VecDeque::new();
        q.push_back((0,0,0));
        visited[0][0][0] = 1;
        while let Some((x,y, breaked)) = q.pop_front() {
            //println!("{} {} {}", x, y, breaked);
            if y == self.n - 1 && x == self.m - 1 {
                return visited[y][x][breaked];
            }
            for (dx, dy) in &d {
                let (nx,ny) = (x as i32 +*dx, y as i32 +*dy);
                if self.check(nx,ny) {
                    if self.map[ny as usize][nx as usize] && breaked == 0 && visited[ny as usize][nx as usize][1] == -1{
                        visited[ny as usize][nx as usize][1] = 1 + visited[y as usize][x as usize][breaked];
                        q.push_back((nx as usize, ny as usize, 1));
                    }
                    if !self.map[ny as usize][nx as usize] && visited[ny as usize][nx as usize][breaked] == -1{
                        visited[ny as usize][nx as usize][breaked] = 1 + visited[y as usize][x as usize][breaked];
                        q.push_back((nx as usize, ny as usize, breaked));
                    }
                }
            }
        }
        return -1;
    }
}
fn main() {
    let mut s = String::new();
    stdin().read_to_string(&mut s).expect("failed to read");
    let mut iter = s.split_whitespace();

    let (n,m) = (iter.read(), iter.read());
    let mut map = vec![vec![false; m];n];
    for i in 0..n {
        let s : String = iter.read();
        for (j,c) in s.chars().enumerate() {
            if c == '1' {
                map[i][j] = true;
            }
        }
    }

    println!("{}", BFS::new(&map).solve());
}
