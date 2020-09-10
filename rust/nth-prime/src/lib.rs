fn is_prime(number: u32) -> bool {
    for factor in 2..((number as f64).sqrt() as u32 + 1) {
        if number % factor == 0 {
            return false;
        }
    }
    return true;
}

pub fn nth(n: u32) -> u32 {
    let mut number = 2;
    for _ in 0..n {
        loop {
            number += 1;
            if is_prime(number) {
                break
            }
        }
    }
    return number;
}

