use std::io::{stdin, Read};
use std::str::{FromStr, SplitWhitespace};
use std::collections::VecDeque;

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}

impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn bfs(state: &mut Vec<Vec<bool>>, start: (usize, usize)) {
    let mut queue = VecDeque::new();
    queue.push_back(start);
    let m = state[0].len();
    let n = state.len();

    let d = [(1,0), (-1,0), (0,1), (0,-1)];
    while let Some(poped) = queue.pop_front() {
        let (x, y) = poped;
        if state[y][x] {
            state[y][x] = false;
            for (dx,dy) in &d {
                let next_x = x as isize+ *dx;
                let next_y = y as isize + *dy;
                if next_x >= 0 && next_x < m as isize && next_y >= 0 && next_y < n as isize && state[next_y as usize][next_x as usize] {
                    queue.push_back((next_x as usize,next_y as usize))
                }
            }
        }
    }
}

fn main() {
    let mut a = Scanner::default();
    let t : u32 = a.next();
    for _ in 0..t {
        let (m,n,k) : (usize, usize, usize) = (a.next(), a.next(), a.next());
        let mut state = vec![vec![false;m]; n];
        for _ in 0..k {
            let (x,y) : (usize, usize) = (a.next(), a.next());
            state[y][x] = true;
        }

        let mut ans = 0;

        for x in 0..m {
            for y in 0..n {
                if !state[y][x] {
                    continue;
                }
                bfs(&mut state, (x, y));
                ans += 1;
            }
        }
        println!("{}",ans);
    }
}
