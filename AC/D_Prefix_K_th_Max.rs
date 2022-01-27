#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(unused)]

use std::cmp::{max, min, Ordering, Reverse};
use std::collections::{BinaryHeap, HashMap, HashSet};
use std::io::{self, prelude::*};
use std::io::{stdin, stdout, BufWriter, Write};
use std::str;
const BITS: usize = 19;
const INF: i64 = 0x3f3f3f3f;

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
    let n: i32 = scan.next();
    let k: i32 = scan.next();
    let mut heap = BinaryHeap::new();
    for i in 0..k {
        let ele: i32 = scan.next();
        heap.push(Reverse(ele));
    }
    let num = heap.peek().unwrap();
    writeln!(out, "{}", num.0);
    for i in k..n {
        let ele: i32 = scan.next();

        if let Some(top) = heap.peek() {
            if top.0 <= ele {
                heap.push(Reverse(ele));
                heap.pop();
            }
        }
        let num = heap.peek().unwrap();
        writeln!(out, "{}", num.0);
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
