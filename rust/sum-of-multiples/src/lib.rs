pub fn sum_of_multiples(limit: u32, factors: &[u32]) -> u32 {
    let mut multiple = Vec::new();
    for i in 1..limit {
        for j in factors.iter() {
            if *j != 0 && i % *j == 0 {
                multiple.push(i);
            }
        }
    }
    multiple.sort();
    multiple.dedup();
    return multiple.iter().sum();
}
