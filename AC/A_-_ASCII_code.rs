#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(unused)]

use std::cmp::{max, min, Reverse};
use std::collections::{BTreeMap, BTreeSet};
use std::io::{self, prelude::*};
use std::io::{stdin, stdout, BufWriter, Write};
use std::str;
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

fn solve() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    let n: u8 = scan.next();
    print!("{}", n as char);
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    // let t: i64 = scan.next();
    // for _ in 0..t {
    //     solve();
    // }
    solve();
}
