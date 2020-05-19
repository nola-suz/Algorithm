use proconio::*;
use std::collections::VecDeque;

fn main() {
    input!{
        n: usize,
        m: usize,
        ab: [(usize, usize); m],
    }


    let mut g = vec![Vec::<usize>::new(); n];
    for (a, b) in ab {
        g[a-1].push(b-1);
        g[b-1].push(a-1);
    }
    let mut q = VecDeque::new();

    let mut ans = vec![200000; n];
    ans[0] = 0;
    for x in &g[0] {
        q.push_back(x);
        ans[*x] = 0;
    }

    while q.len() > 0 {
        let front: usize = *q.pop_front().unwrap();
        for x in &g[front] {
            if ans[*x] < n {
                continue;
            }
            ans[*x] = front;
            q.push_back(x);
        }
    }

    println!("Yes");
    for (i, x) in ans.iter().enumerate() {
        if i == 0 {
            continue;
        }
        println!("{}", *x + 1);
    }
}
