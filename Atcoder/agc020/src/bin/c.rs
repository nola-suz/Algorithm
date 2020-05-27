/// https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let mut s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};

    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };

    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };

    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };

    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };

    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

fn main() {
    input!{
        n: usize,
        a: [usize; n],
    }

    // let n = 1;
    // let a = vec![58];

    let mut sum = 0;

    let mut bitset = bitset::BitSet::from(1);
    // println!("{:?}", bitset.bits);
    for &x in a.iter() {
        bitset |= bitset.clone() << x;
        sum += x;
        // println!("{:?}", bitset.bits);
    }

    for i in (sum+1)/2..sum+1 {
        if bitset.get(i) {
            println!("{}", i);
            return;
        }
    }
}

pub mod bitset {
    use std::ops::*;
    const BIT_LENGTH: usize = 63;

    #[derive(Clone)]
    pub struct BitSet {
        pub bits: Vec<u64>,
    }

    impl From<usize> for BitSet {
        fn from(n: usize) -> Self {
            BitSet { bits: vec![n as u64] }
        }
    }

    /// #Example
    ///
    /// ```
    /// let bits = bitset::BitSet::new(3);
    /// let bits |= bitset::BitSet::from(9);
    /// assert_eq!(bits, bitset::BitSet{ bits: vec![3|9] });
    /// ```
    impl BitOrAssign for BitSet {
        fn bitor_assign(&mut self, rhs: Self) {
            for i in 0..self.bits.len() {
                if i < rhs.bits.len() {
                    self.bits[i] |= rhs.bits[i];
                }
            }

            if self.bits.len() < rhs.bits.len() {
                for i in self.bits.len()..rhs.bits.len() {
                    self.bits.push(rhs.bits[i])
                }
            }
        }
    }

    /// #Example
    ///
    /// ```
    /// let bits = bitset::Bitset::new(1);
    /// let bits = bits << 2;
    /// assert_eq!(bits, bitset::BitSet{ bits: vec![4] });
    /// ```
    impl Shl<usize> for BitSet {
        type Output = Self;

        fn shl(self, rhs: usize) -> Self::Output {
            self.shift_left(rhs)
        }
    }

    impl BitSet {
        pub fn new(n: usize) -> Self {
            let bits_size = (n + BIT_LENGTH - 1) / BIT_LENGTH;
            BitSet{
                bits: vec![0; bits_size],
            }
        }

        pub fn get(&self, n: usize) -> bool {
            if n / BIT_LENGTH < self.bits.len() {
                (self.bits[n / BIT_LENGTH] & (1u64 << (n as u64 % BIT_LENGTH as u64))) > 0
            } else {
                false
            }
        }

        pub fn shift_left(&self, shift: usize) -> Self {
            let geta = shift / BIT_LENGTH;
            let slide_length = shift as u64 % BIT_LENGTH as u64;
            let mut ret = vec![0; geta];

            let mut pre = 0;
            for &bit in self.bits.iter() {
                let overflow = (bit >> (BIT_LENGTH as u64 - slide_length)) << (BIT_LENGTH as u64 - slide_length);
                let push_val = ((bit - overflow) << slide_length) + pre;
                pre = overflow >> (BIT_LENGTH as u64 - slide_length);
                ret.push(push_val);
            }
            if pre > 0 {
                ret.push(pre);
            }

            BitSet {
                bits: ret,
            }
        }
    }
}
