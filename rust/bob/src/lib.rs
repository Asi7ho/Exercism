pub fn reply(message: &str) -> &str {
    return if message.trim().is_empty() {
        "Fine. Be that way!"
    } else if !message
        .trim()
        .chars()
        .filter(|x| x.is_alphabetic())
        .collect::<String>()
        .is_empty()
        && message
            .chars()
            .filter(|x| x.is_alphabetic())
            .all(|x| x.is_uppercase())
        && message.trim().chars().last().unwrap() == '?'
    {
        "Calm down, I know what I'm doing!"
    } else if message.trim().chars().last().unwrap() == '?' {
        "Sure."
    } else if !message
        .trim()
        .chars()
        .filter(|x| x.is_alphabetic())
        .collect::<String>()
        .is_empty()
        && message
            .chars()
            .filter(|x| x.is_alphabetic())
            .all(|x| x.is_uppercase())
    {
        "Whoa, chill out!"
    } else {
        "Whatever."
    };
}
