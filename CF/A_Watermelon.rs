#[allow(unused_imports)]
#[allow(dead_code)]
use std::cmp::{max, min};
use std::io::{stdin, stdout, BufWriter, Write};
// const BITS: usize = 19;
// const INF: i64 = 0x3f3f3f3f;

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n: i32 = scan.next();
    if n % 2 == 1 || n == 2 {
        write!(out, "NO").ok();
    } else {
        write!(out, "YES").ok();
    }
}
