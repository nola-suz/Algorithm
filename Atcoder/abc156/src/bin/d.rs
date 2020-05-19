#[warn(unused_mut)]
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

#[warn(unused_mut)]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};

    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[warn(unused_mut)]
macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };

    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };

    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };

    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };

    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

/// ans = 2^n - comb(n, a) - comb(n, b)
/// comb(n, k) = n * (n-1) * ... * (n-a+1) / a / (a-1) / ... / 1

fn my_pow(n: u64, a: u64) -> u64 {
    let mut ret = 1;
    let mut tmp = a;
    let mut n = n;
    while n > 0 {
        if n & 1 == 1 {
            ret *= tmp;
            ret %= 1000000007;
        }

        tmp *= tmp;
        tmp %= 1000000007;
        n /= 2;
    }

    ret
}

fn mod_inv(n: u64) -> u64 {
    return my_pow(1000000005, n);
}

fn comb(n: u64, k: u64) -> u64 {
    let mut ret = 1;

    for i in n-k+1..n+1 {
        ret *= i;
        ret %= 1000000007;
    }

    for i in 1..k+1 {
        ret *= mod_inv(i);
        ret %= 1000000007;
    }

    ret
}

fn main() {
    input!{
        n: u64,
        a: u64,
        b: u64,
    }

    let mut ans = my_pow(n, 2);
    ans = (ans + 1000000007 - comb(n, a)) % 1000000007;
    ans = (ans + 1000000007 - comb(n, b)) % 1000000007;
    ans -= 1;
    println!("{}", ans);
}
