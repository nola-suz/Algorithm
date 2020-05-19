use proconio::*;

fn main() {
    input!{
        k: usize,
        s: String,
    }

    if s.len() > k {
        println!("{}...", &s[0..k]);
    }
    else {
        println!("{}", s.as_str());
    }
}
