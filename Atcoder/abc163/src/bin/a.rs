// competitive-rs | MIT License | github.com/tanakh/competitive-rs/blob/master/LICENSE
use competitive::prelude::*;
use competitive::number::*;
use std::f64::consts::PI;

fn main() {
    input!{
        r: f64,
    }

    println!("{}", r * PI * 2.0);
}
