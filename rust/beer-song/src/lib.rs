pub fn verse(n: u32) -> String {
    //unimplemented!("emit verse {}", n)
    if n == 0 {
        return String::from("No more bottles of beer on the wall, no more bottles of beer.\n\
    Go to the store and buy some more, 99 bottles of beer on the wall.\n");
    }

    if n == 1 {
        return String::from(format!("{} bottle of beer on the wall, {} bottle of beer.\n\
    Take it down and pass it around, no more bottles of beer on the wall.\n", n, n));
    }

    if n == 2 {
        return String::from(format!("{} bottles of beer on the wall, {} bottles of beer.\n\
    Take one down and pass it around, {} bottle of beer on the wall.\n", n, n, n-1));
    }

    return String::from(format!("{} bottles of beer on the wall, {} bottles of beer.\n\
    Take one down and pass it around, {} bottles of beer on the wall.\n", n, n, n-1));
}

pub fn sing(start: u32, end: u32) -> String {
    // unimplemented!("sing verses {} to {}, inclusive", start, end)
    let mut song:String = String::new();

    for n in (end..=start).rev(){
        song.push_str(verse(n).as_str());
        if n != end {
            song.push_str("\n");
        }
    }

    return song;
}
