// competitive-rs | MIT License | github.com/tanakh/competitive-rs/blob/master/LICENSE
use competitive::prelude::*;

fn main() {
    input!{
        n: i32,
        m: i32,
        a: [i32; m],
    }

    let mut sum = 0;

    for i in a.iter() {
        sum += i;
    }

    println!("{}", if sum > n { -1 } else { n - sum });
}
