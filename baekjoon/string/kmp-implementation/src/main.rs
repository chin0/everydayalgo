#[allow(unused_input)]

use std::io::{BufWriter, stdin, stdout, Write};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}

impl Scanner {
    fn next(&mut self) -> impl std::str::FromStr {
        loop {
            
        }
    }
}
struct Matcher<'a, C: Eq> {
    pattern: &'a [C],
    fail: Vec<usize>,
}

impl<'a, C:Eq> Matcher<'a, C> {
    fn new(pattern: &'a [C]) -> Self {
        let mut fail = Vec::with_capacity(pattern.len());
        fail.push(0);
        let mut j = 0;
        for ch in &pattern[1..] {
            // i번째 문자랑 j번째 문자랑 비교해서 틀리면 j = pi[j-1].
            while j > 0 && pattern[j] != *ch {
                j = fail[j -1];
            }
            // 만약 맞다면 j를 한칸 옮겨줌.
            if pattern[j] == *ch {
                j += 1;
            }
            // 현재 j값이 pi값이 된다.
            fail.push(j);
        }
        Self { pattern, fail }
    }

    fn kmp_match(&self, text: impl IntoIterator<Item = C>) -> Vec<usize> {
        let mut len = 0;
        let mut result = Vec::new();
        text.into_iter()
            .enumerate()
            .for_each(|(i,ch)| {
                while len > 0 && self.pattern[len] != ch {
                    len = self.fail[len - 1];
                }

                if self.pattern[len] == ch {
                    len += 1;
                }
                if len == self.pattern.len() {
                    result.push(i+1-len);
                    len = self.fail[len - 1];
                }
            });
       result
    }
}
fn main() {

}
