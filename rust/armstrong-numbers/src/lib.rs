pub fn is_armstrong_number(num: u32) -> bool {
    // unimplemented!("true if {} is an armstrong number", num)
    let num_vec = number_to_vec(num);
    let length_vec = num_vec.len() as u32;
    let mut s = 0;
    for n in num_vec.iter() {
        s += n.pow(length_vec);
    }

    return s == num
}

pub fn number_to_vec(n: u32) -> Vec<u32> {
    n.to_string()
        .chars()
        .map(|c| c.to_digit(10).unwrap())
        .collect()
}
