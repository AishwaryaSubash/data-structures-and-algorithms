fn length_of_longest_substring(s: String) -> i32 {
    let mut max: u32 = 0;
    for i in 0..s.len() {
        for j in i + 1..s.len() + 1 {
            if !s[i..j].eq("") {
                let vt: Vec<char> = s[i..j].chars().collect();
                let mut y = vt.clone();
                y.sort();
                y.dedup();
                if vt.len() == y.len() && s[i..j].to_string().len() as u32 > max {
                    max = s[i..j].to_string().len() as u32;
                }
            }
        }
    }
    return max as i32;
}
