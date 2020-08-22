use proconio::*;

fn main() {
    input! {
        n: usize,
        x: usize,
        t: usize,
    }

    println!("{}", (n + x - 1) / x * t);
}
