pub fn brackets_are_balanced(string: &str) -> bool {

    let mut bracket_stack = vec![];

    for c in string.chars() {
        match c {
            '[' => bracket_stack.push(']'),
            '(' => bracket_stack.push(')'),
            '{' => bracket_stack.push('}'),
            ']' | ')' | '}' => {
                if bracket_stack.pop() != Some(c) {
                    return false;
                }
            },
            _ => {}
        }
    }

    return bracket_stack.is_empty();
}
