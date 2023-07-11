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

fn solve(mp: &BTreeSet<i64>) {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    let n: i64 = scan.next();
    if mp.contains(&n) {
        println!("YES");
    } else {
        println!("NO");
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let mut nums: BTreeSet<i64> = BTreeSet::new();
    for i in 2..1000 {
        let mut sum: i64 = 1 + i + i * i;
        let mut pow: i64 = i * i;
        nums.insert(sum);
        while sum + pow * i <= 1e6 as i64 {
            pow *= i;
            sum += pow;
            nums.insert(sum);
        }
    }

    // eprintln!("{:?}!", nums);

    let t: i64 = scan.next();
    for _ in 0..t {
        solve(&nums);
    }
    // solve();
}
