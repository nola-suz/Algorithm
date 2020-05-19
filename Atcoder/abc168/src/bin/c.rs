use proconio::*;

fn main() {
    input!{
        a: f64,
        b: f64,
        h: f64,
        m: f64,
    }

    let hrad = 360f64 * (h / 12f64) + (360f64 / 12f64) * (m / 60f64);
    let mrad = 360f64 * (m / 60f64);

    let rad_diff_pi = (hrad - mrad).abs().min((360f64 - (hrad - mrad)).abs());
    let rad_diff_pi = rad_diff_pi / 180f64 * std::f64::consts::PI;

    let ans = (a*a + b*b - 2f64 * a * b * rad_diff_pi.cos()).sqrt();

    println!("{}", ans);
}
