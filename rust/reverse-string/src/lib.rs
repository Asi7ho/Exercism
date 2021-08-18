use unicode_segmentation::UnicodeSegmentation;

pub fn reverse(input: &str) -> String {
    // Basic solution
    // return input.chars().rev().collect();

    // Global solution
    return input.graphemes(true).rev().collect();
}
