// competitive-rs | MIT License | github.com/tanakh/competitive-rs/blob/master/LICENSE
use competitive::prelude::*;
use competitive::number::*;

def_gf!(1000000007);

fn main() {
    input!{
        n: usize,
        k: usize,
    }

    let k = min(n-1, k);
    let table = gen_fact_table::<GF>(n * 2);
    let mut ans: GF = GF::new(0);
    for i in 0..=k {
        ans += comb_from_table(n, i, &table) * comb_from_table(n-1, i, &table);
    }

    echo!(ans);
}