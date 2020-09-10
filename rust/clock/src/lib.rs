use std::fmt;

#[derive(Debug, Eq, PartialOrd, PartialEq)]
pub struct Clock {
    hours: i32,
    minutes: i32,
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        let total_min = (hours * 60 + minutes).rem_euclid(24 * 60);
        return Clock {
            hours: total_min / 60,
            minutes: total_min % 60,
        };
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        return Self::new(self.hours, self.minutes + minutes);
    }
}

impl fmt::Display for Clock {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        return write!(f, "{:02}:{:02}", self.hours, self.minutes);
    }
}