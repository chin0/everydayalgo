use std::io::stdin;

//반복되는 문자열 구조에서 kmp의 실패함수를 떠올려야함.
//만약 문자열이 반복문자열이라면 fail[N-1](실패함수의 마지막 값)은 무조건 0 이상이다.
//만약 s가 반복문자열이라면 s의 길이는 어떤 k에 대하여 kn이 되어야하고 s[0] == s[3] .. == s[nk]
// s[1] == s[4] == ... == s[nk+1], 이런 꼴이므로 실패함수의 정의에 따라서 무조건 fail[N-1]=(k-1)n이 될수밖에 없음.
//그러므로 N - fail[N-1]은 반복문자열의 길이가 되고 정답은 N/(N-fail[N-1])이 될것임..
// 단, N-fail[N-1]이 확실히 N의 배수인지 확인해야한다.
//N의 배수인지 확인을 안했을때 문제는, abababa 이 문자열을 보자. 이 문자열은 명백히 반복문자열은 아니지만 fail[N-1]=5, N-fail[N-1]=2이므로 저 식대로 계산하면 3이 나오게된다.
struct Matcher<'a,C: Eq> {
    pattern: &'a [C],
    fail: Vec<usize>
}

impl<'a, C: Eq> Matcher<'a, C> {
    fn new(s: &'a [C]) -> Self {
        let mut result = Vec::new();
        result.push(0);
        let mut j = 0;
        for c in &s[1..] {
            while j > 0 && s[j] != *c { j = result[j-1] }
            if s[j] == *c {
                j += 1
            }
            result.push(j);
        }

        Self {
            pattern: s,
            fail: result
        }
    }
}
fn main() {
    loop {
        let mut s = String::new();
        stdin().read_line(&mut s).expect("failed to read");
        let s = s[0..s.len()-1].as_bytes();
        if s == b"." {
            break;
        }
        let matcher = Matcher::new(s);
        let p = s.len() - matcher.fail[s.len() - 1];

        //abababa와 같은 경우 처리가 필요함. 이 경우 p가 s.len()의 배수인지 알아보면 된다.
        let ans;
        if s.len() % p == 0 {
            ans = s.len() / (s.len() - matcher.fail[s.len()-1]);
        } else {
            ans = 1;
        }
        println!("{}", ans);
    }
}
