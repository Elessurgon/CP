#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(unused)]

use std::cmp::{max, min, Reverse};
use std::collections::{HashMap, HashSet};
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
    let n: i64 = scan.next();
    let mut v: Vec<i64> = (0..n).map(|_| scan.next()).collect();
    let mut sum: i64 = v[0];

    for i in 1..n as usize {
        sum ^= v[i];
    }
    let mut a: Vec<i64> = vec![0; n as usize];
    for i in 0..n as usize {
        a[i] = v[i] ^ sum;
    }
    for e in a {
        print!("{} ", e);
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    // let t: i64 = scan.next();
    // for _ in 0..t {
    // solve();
    // }
    solve();
}
