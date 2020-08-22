use proconio::{marker::*, *};
use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(Copy, Clone, Eq, PartialEq)]
struct State {
    cost: usize,
    position: (usize, usize),
}

impl Ord for State {
    fn cmp(&self, other: &State) -> Ordering {
        other
            .cost
            .cmp(&self.cost)
            .then_with(|| self.position.cmp(&other.position))
    }
}

impl PartialOrd for State {
    fn partial_cmp(&self, other: &State) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn inside(y: i32, x: i32, h: usize, w: usize) -> bool {
    0 <= y && y < h as i32 && 0 <= x && x < w as i32
}

fn main() {
    input! {
        h: usize,
        w: usize,
        c: (Usize1, Usize1),
        d: (Usize1, Usize1),
        s: [Chars; h],
    }

    let mut heap = BinaryHeap::new();
    let mut costs = vec![vec![1_000_000_000usize; w]; h];

    costs[c.0][c.1] = 0;
    heap.push(State {
        cost: 0,
        position: c.clone(),
    });

    let dd = vec![1, 0, -1, 0, 1];
    while let Some(State { cost, position }) = heap.pop() {
        let (y, x) = position;
        if cost > costs[y][x] {
            continue;
        }
        for i in 0..4 {
            let (ny, nx) = (y as i32 + dd[i], x as i32 + dd[i+1]);
            if !inside(ny, nx, h, w) {
                continue
            }

            let (ny, nx) = (ny as usize, nx as usize);

            if s[ny][nx] == '#' || cost >= costs[ny][nx] {
                continue;
            }

            costs[ny][nx] = cost;
            heap.push(State {
                cost,
                position: (ny, nx),
            });
        }

        for yy in -2..=2 {
            for xx in -2..=2 {
                let (ny, nx) = (y as i32 + yy, x as i32 + xx);
                if !inside(ny, nx, h, w) {
                    continue
                }

                let (ny, nx) = (ny as usize, nx as usize);

                if s[ny][nx] == '#' || cost + 1 >= costs[ny][nx] {
                    continue;
                }

                costs[ny][nx] = cost + 1;
                heap.push(State {
                    cost: cost + 1,
                    position: (ny, nx),
                });
            }
        }
    }

    println!("{}", if costs[d.0][d.1] != 1_000_000_000 { costs[d.0][d.1] as i32 } else { -1 });
}
