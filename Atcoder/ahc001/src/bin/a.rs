use proconio::*;
use std::ops::Sub;

#[derive(Copy, Clone, Debug)]
struct Pos {
    x: i32,
    y: i32,
}

impl Pos {
    pub fn add(&self, a: i32, b: i32) -> Pos {
        Pos {
            x: self.x + a,
            y: self.y + b,
        }
    }
}

impl PartialEq for Pos {
    fn eq(&self, other: &Self) -> bool {
        self.x == other.x && self.y == other.y
    }
}

#[derive(Copy, Clone, Debug)]
struct Ad {
    // hidari ue
    lu: Pos,
    // migi shita
    rd: Pos,
}

impl Ad {
    pub fn get_area(&self) -> i32 {
        (self.rd.x - self.lu.x) * (self.rd.y - self.lu.y)
    }
}

impl PartialEq for Ad {
    fn eq(&self, other: &Self) -> bool {
        self.lu == other.lu && self.rd == other.rd
    }
}

#[derive(Copy, Clone, Debug)]
struct Request {
    pos: Pos,
    r: i32,
    id: usize,
}

impl PartialEq for Request {
    fn eq(&self, other: &Self) -> bool {
        self.id == other.id
    }
}

fn main() {
    input! {
        n: usize,
        xyz: [(i32, i32, i32); n],
    }

    let mut requests = xyz
        .into_iter()
        .enumerate()
        .map(|(i, x)| Request {
            pos: Pos { x: x.0, y: x.1 },
            r: x.2,
            id: i,
        })
        .collect::<Vec<_>>();

    requests.sort_by_key(|&x| x.r);

    let ng_pos = Pos { x: -1, y: -1 };
    let mut res = vec![
        Ad {
            lu: ng_pos.clone(),
            rd: ng_pos.clone(),
        };
        n
    ];

    for &req in requests.iter() {
        res[req.id] = choice(&res, &req, &requests);
    }

    for &r in res.iter() {
        println!("{} {} {} {}", r.lu.x, r.lu.y, r.rd.x, r.rd.y);
    }
}

fn choice(res: &[Ad], req: &Request, reqs: &[Request]) -> Ad {
    let mut ret = Ad {
        lu: req.pos.clone(),
        rd: req.pos.clone(),
    };

    ret.rd = ret.rd.add(1, 1);

    if !check_ads(res, &ret) {
        return outside_pick(res);
    }

    loop {
        let next = get_next(res, &ret, req.r, reqs, req);
        if next != ret {
            ret = next;
            continue;
        }

        let next2 = get_next2(res, &ret, req.r, reqs, req);
        if next2 != ret {
            ret = next2;
            continue;
        }

        // println!("next: {} x {} = {}", next.rd.x - next.lu.x, next.rd.y - next.lu.y, next.get_area());
        // println!("next2: {} x {} = {}", next2.rd.x - next2.lu.x, next2.rd.y - next2.lu.y, next2.get_area());
        // println!("ret: {} x {} = {}", ret.rd.x - ret.lu.x, ret.rd.y - ret.lu.y, ret.get_area());
        // println!("area: {}, id: {}", req.r, req.id);
        return ret;
    }
}

fn get_next(res: &[Ad], ad: &Ad, area: i32, reqs: &[Request], req: &Request) -> Ad {
    let mut candidate1 = vec![ad.clone()];
    let mut candidate2 = vec![ad.clone()];
    {
        let mut left_expand = ad.clone();
        left_expand.lu.x -= 1;
        if is_inside(&left_expand) && check_ads(res, &left_expand) {
            if check_ad_no_wrap(&left_expand, reqs, req) {
                candidate1.push(left_expand);
            } else {
                candidate2.push(left_expand);
            }
        }
    }
    {
        let mut up_expand = ad.clone();
        up_expand.lu.y -= 1;
        if is_inside(&up_expand) && check_ads(res, &up_expand) {
            if check_ad_no_wrap(&up_expand, reqs, req) {
                candidate1.push(up_expand);
            } else {
                candidate2.push(up_expand);
            }
        }
    }
    {
        let mut right_expand = ad.clone();
        right_expand.rd.x += 1;
        if is_inside(&right_expand) && check_ads(res, &right_expand) {
            if check_ad_no_wrap(&right_expand, reqs, req) {
                candidate1.push(right_expand);
            } else {
                candidate2.push(right_expand);
            }
        }
    }
    {
        let mut down_expand = ad.clone();
        down_expand.rd.y += 1;
        if is_inside(&down_expand) && check_ads(res, &down_expand) {
            if check_ad_no_wrap(&down_expand, reqs, req) {
                candidate1.push(down_expand);
            } else {
                candidate2.push(down_expand);
            }
        }
    }

    candidate1.sort_by_key(|&x| x.get_area().sub(area).abs());
    if let Some(fi) = candidate1.first() {
        if *fi != ad.clone() {
            return *fi;
        }
    }
    candidate2.sort_by_key(|&x| x.get_area().sub(area).abs());
    *candidate2.first().unwrap()
}

fn get_next2(res: &[Ad], ad: &Ad, area: i32, reqs: &[Request], req: &Request) -> Ad {
    if ad.get_area() <= area {
        return ad.clone();
    }

    let mut candidate1 = vec![ad.clone()];
    let mut candidate2 = vec![ad.clone()];
    {
        let mut left_expand = ad.clone();
        left_expand.lu.x -= 1;

        left_expand.lu.y += 1;
        if is_inside(&left_expand) && check_ads(res, &left_expand) {
            if check_ad_no_wrap(&left_expand, reqs, req) {
                candidate1.push(left_expand.clone());
            } else {
                candidate2.push(left_expand.clone());
            }
        }
        left_expand.lu.y -= 1;
        left_expand.rd.y -= 1;
        if is_inside(&left_expand) && check_ads(res, &left_expand) {
            if check_ad_no_wrap(&left_expand, reqs, req) {
                candidate1.push(left_expand.clone());
            } else {
                candidate2.push(left_expand.clone());
            }
        }
    }
    {
        let mut up_expand = ad.clone();
        up_expand.lu.y -= 1;

        up_expand.lu.x += 1;
        if is_inside(&up_expand) && check_ads(res, &up_expand) {
            if check_ad_no_wrap(&up_expand, reqs, req) {
                candidate1.push(up_expand.clone());
            } else {
                candidate2.push(up_expand.clone());
            }
        }

        up_expand.lu.x -= 1;
        up_expand.rd.x -= 1;

        if is_inside(&up_expand) && check_ads(res, &up_expand) {
            if check_ad_no_wrap(&up_expand, reqs, req) {
                candidate1.push(up_expand.clone());
            } else {
                candidate2.push(up_expand.clone());
            }
        }
    }
    {
        let mut right_expand = ad.clone();
        right_expand.rd.x += 1;

        right_expand.lu.y += 1;
        if is_inside(&right_expand) && check_ads(res, &right_expand) {
            if check_ad_no_wrap(&right_expand, reqs, req) {
                candidate1.push(right_expand.clone());
            } else {
                candidate2.push(right_expand.clone());
            }
        }
        right_expand.lu.y -= 1;
        right_expand.rd.y -= 1;
        if is_inside(&right_expand) && check_ads(res, &right_expand) {
            if check_ad_no_wrap(&right_expand, reqs, req) {
                candidate1.push(right_expand.clone());
            } else {
                candidate2.push(right_expand.clone());
            }
        }
    }
    {
        let mut down_expand = ad.clone();
        down_expand.rd.y += 1;

        down_expand.lu.x += 1;
        if is_inside(&down_expand) && check_ads(res, &down_expand) {
            if check_ad_no_wrap(&down_expand, reqs, req) {
                candidate1.push(down_expand.clone());
            } else {
                candidate2.push(down_expand.clone());
            }
        }

        down_expand.lu.x -= 1;
        down_expand.rd.x -= 1;

        if is_inside(&down_expand) && check_ads(res, &down_expand) {
            if check_ad_no_wrap(&down_expand, reqs, req) {
                candidate1.push(down_expand.clone());
            } else {
                candidate2.push(down_expand.clone());
            }
        }
    }

    candidate1.sort_by_key(|&x| x.get_area().sub(area).abs());
    if let Some(fi) = candidate1.first() {
        if *fi != ad.clone() {
            return *fi;
        }
    }
    candidate2.sort_by_key(|&x| x.get_area().sub(area).abs());
    *candidate2.first().unwrap()
}

fn is_inside(ad: &Ad) -> bool {
    ad.lu.x >= 0 && ad.lu.y >= 0 && ad.rd.x <= 10000 && ad.rd.y <= 10000
}

fn check_ads(res: &[Ad], ad: &Ad) -> bool {
    for &r in res.iter() {
        if !check_ad(&r, &ad) {
            return false;
        }
    }

    true
}

fn check_ad_no_wrap(ad: &Ad, reqs: &[Request], req: &Request) -> bool {
    for &r in reqs.iter() {
        if *req == r {
            continue;
        }

        let tmp = Ad {
            lu: r.pos.clone(),
            rd: r.pos.clone().add(1, 1),
        };

        if !check_ad(&tmp, ad) {
            return false;
        }
    }

    true
}

fn check_ad(a: &Ad, b: &Ad) -> bool {
    if a.lu.x < 0 || b.lu.x < 0 {
        return true;
    }
    a.rd.y <= b.lu.y || a.rd.x <= b.lu.x || b.rd.y <= a.lu.y || b.rd.x <= a.lu.x
}

fn outside_pick(res: &[Ad]) -> Ad {
    let mut pos = Pos { x: 9999, y: 9999 };

    loop {
        let ad = Ad {
            lu: pos.clone(),
            rd: pos.clone().add(1, 1),
        };

        if check_ads(res, &ad) {
            return ad;
        }

        pos = pos.add(-1, 0);
        if pos.x == -1 {
            pos = Pos {
                x: 9999,
                y: pos.y - 1,
            }
        }
    }
}
