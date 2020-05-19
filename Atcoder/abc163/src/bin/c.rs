// competitive-rs | MIT License | github.com/tanakh/competitive-rs/blob/master/LICENSE
use competitive::prelude::*;

fn main() {
    input!{
        n: usize,
        a: [usize; n-1],
    }

    let mut ans = vec![0; n];
    for aa in a {
        ans[aa-1] += 1;
    }

    for i in ans {
        println!("{}", i);
    }
}
