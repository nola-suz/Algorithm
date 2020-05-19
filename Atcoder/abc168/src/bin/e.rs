use num::integer::gcd;
use proconio::*;
use std::collections::HashMap;

fn main() {
    #![allow(non_snake_case)]
    let MOD: i64 = 1_000_000_007;
    input! {
        n: usize,
        ab: [(i64, i64); n],
    }

    let mut map = HashMap::new();

    // # of (0, 0)
    let mut ans1 = 0i64;
    // # of (0, x)
    let mut ans2 = 0i64;
    // # of (x, 0)
    let mut ans3 = 0i64;

    for (a, b) in ab {
        if (a, b) == (0, 0) {
            ans1 += 1;
            continue;
        }
        if a == 0 {
            ans2 += 1;
            continue;
        }
        if b == 0 {
            ans3 += 1;
            continue;
        }
        let mut aa = a / gcd(a, b);
        let mut bb = b / gcd(a, b);

        if aa < 0 {
            aa *= -1;
            bb *= -1;
        }

        *map.entry((aa, bb)).or_insert(0) += 1;
    }

    let mut pow2 = [1i64; 300001];
    for i in 1..300001 {
        pow2[i] = pow2[i - 1] * 2;
        pow2[i] %= MOD;
    }

    let mut ans = 1i64;
    ans *= (pow2[ans2 as usize] + pow2[ans3 as usize] - 1) % MOD;
    ans %= MOD;

    let tmap = map.clone();
    for (key, _) in tmap.iter() {
        let key1 = *key;
        let key2 = (key1.1.abs(), key1.0 * if key1.1 < 0 { 1 } else { -1 });
        let val1 = map.entry(key1).or_default().clone();
        let val2 = map.entry(key2).or_default().clone();

        let mut tmp = pow2[val1 as usize] + pow2[val2 as usize] - 1;
        tmp %= MOD;
        ans *= tmp;
        ans %= MOD;

        map.entry(key1).and_modify(|x| *x = 0);
        map.entry(key2).and_modify(|x| *x = 0);
    }

    println!("{}", (ans - 1 + ans1 + MOD) % MOD);
}
