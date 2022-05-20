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

fn eq(a: &Vec<i64>, b: &Vec<i64>) -> bool {
    for i in 0..a.len() as usize {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

fn solve() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    let n: i64 = scan.next();
    let m: i64 = scan.next();
    let mut a: Vec<Vec<i64>> = vec![vec![0; m as usize]; n as usize];

    for i in 0..n as usize {
        for j in 0..m as usize {
            a[i][j] = scan.next();
        }
    }

    let mut ind1: usize = 0;
    let mut ind2: usize = 0;
    let mut i1: bool = false;
    let mut i2: bool = false;

    let mut b = a.clone();

    for i in 0..n as usize {
        a[i].sort();
    }

    for i in 0..n as usize {
        let mut test: i64 = 0;
        for j in 0..m as usize {
            if a[i][j] != b[i][j] {
                // eprint!("j={}\n", j);
                if !i1 {
                    ind1 = j;
                    i1 = true;
                } else {
                    ind2 = j;
                    i2 = true;
                }

                test += 1;
            }
        }

        if test > 2 {
            // eprintln!("ERROR");
            println!("{}", -1);
            return;
        }
    }
    // eprintln!("id1={} id2={}", ind1 + 1, ind2 + 1);
    if !i1 && !i2 {
        println!("1 1");
        return;
    }

    for i in 0..n as usize {
        let t = b[i][ind1];
        b[i][ind1] = b[i][ind2];
        b[i][ind2] = t;
    }

    // for i in 0..n as usize {
    //     for j in 0..m as usize {
    //         eprint!("{} ", b[i][j]);
    //     }
    //     eprint!("\n");
    // }
    // eprint!("\n");

    for i in 0..n as usize {
        let mut test: i64 = 0;
        for j in 0..m as usize {
            if a[i][j] != b[i][j] {
                test += 1;
            }
        }
        if test > 0 {
            println!("{}", -1);
            return;
        }
    }
    println!("{} {}", ind1 + 1, ind2 + 1);
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t: i64 = scan.next();
    for _ in 0..t {
        solve();
    }
    // solve();
}
