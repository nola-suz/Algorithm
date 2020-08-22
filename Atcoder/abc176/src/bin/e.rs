use proconio::{*, marker::*};
use std::collections::BTreeSet;

fn main() {
    input! {
        h: usize,
        w: usize,
        m: usize,
        hw: [(Usize1, Usize1); m],
    }

    let mut hh = vec![0; h];
    let mut ww = vec![0; w];

    for &(y, x) in hw.iter() {
        hh[y] += 1;
        ww[x] += 1;
    }

    let mut h_max = 0;
    for i in 0..h {
        h_max = h_max.max(hh[i]);
    }

    let mut w_max = 0;
    for i in 0..w {
        w_max = w_max.max(ww[i]);
    }

    let mut h_maxs = BTreeSet::new();
    for i in 0..h {
        if h_max == hh[i] {
            h_maxs.insert(i);
        }
    }
    let mut w_maxs = BTreeSet::new();
    for i in 0..w {
        if w_max == ww[i] {
            w_maxs.insert(i);
        }
    }

    let mut cross_cnt = 0;
    for &(y, x) in hw.iter() {
        if h_maxs.contains(&y) && w_maxs.contains(&x) {
            cross_cnt += 1;
        }
    }

    let mut ans = h_max + w_max - 1;

    // println!("{:?}", h_maxs);
    // println!("{:?}", w_maxs);
    // println!("{}", cross_cnt);
    if cross_cnt < h_maxs.len() * w_maxs.len() {
        ans += 1;
    }

    println!("{}", ans);
}
