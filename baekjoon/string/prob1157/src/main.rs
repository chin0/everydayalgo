use std::io::stdin;

fn main() {
    let mut s = String::new();
    stdin().read_line(&mut s).expect("failed to read.");
    let s = s.trim().to_ascii_uppercase();

    let mut cntlist = [0; 26];
    s.bytes().for_each(|x| cntlist[(x - b'A') as usize] += 1);
    let mut max = s.as_bytes()[0];
    for c in s.bytes().skip(1) {
        if cntlist[(c - b'A') as usize] > cntlist[(max - b'A') as usize] {
            max = c;
        }
    }
    if cntlist.iter().filter(|x| **x == cntlist[(max - b'A') as usize]).count() > 1 {
        println!("{}", '?');
    } else {
        println!("{}", max as char);
    }
}
