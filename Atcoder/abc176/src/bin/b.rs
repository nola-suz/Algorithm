use proconio::{marker::Chars, *};

fn main() {
    input! {
        n: Chars,
    }

    let n: Vec<i32> = n
        .into_iter()
        .collect::<Vec<char>>()
        .iter()
        .map(|x| *x as i32 - 48)
        .collect::<Vec<i32>>();
    let mut sum = 0;
    for i in n {
        sum += i;
        sum %= 9;
    }

    println!("{}", if sum == 0 { "Yes" } else { "No" });
}
