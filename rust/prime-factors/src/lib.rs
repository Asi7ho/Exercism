pub fn factors(n: u64) -> Vec<u64> {

    let mut factors = Vec::new();
    let mut mult = n;
    let mut f = 2;

    while mult != 1 {
        if mult % f == 0 {
            mult /= f;
            factors.push(f);
        } else {
            f += 1;
        }
    }
    return factors;
}
