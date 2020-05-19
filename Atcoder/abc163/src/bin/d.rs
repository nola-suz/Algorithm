// competitive-rs | MIT License | github.com/tanakh/competitive-rs/blob/master/LICENSE
use competitive::prelude::*;

fn main() {
    input!{
        n: i64,
        k: i64,
    }

    let mut ans = 0i64;
    let mm = 1000000007i64;
    let mut l = 0i64;
    let mut r = 0i64;

    for i in 0..n+1 {
        l += i;
        r += n - i;
        if i+1 >= k {
            ans += r - l + 1;
            ans %= mm;
        }
    }

    println!("{}", ans);
}
