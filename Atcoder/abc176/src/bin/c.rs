use proconio::*;

fn main() {
    input! {
        n: usize,
        a: [usize; n],
    }

    let mut mn = 0;
    let mut ans = 0;

    for i in a {
        if i < mn {
            ans += mn - i;
        }
        mn = mn.max(i);
    }

    println!("{}", ans);
}
