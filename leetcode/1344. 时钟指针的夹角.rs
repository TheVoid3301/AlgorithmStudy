impl Solution {
    pub fn angle_clock(hour: i32, minutes: i32) -> f64 {
        let one_minute_angle = 6;
        let one_hour_angle = 30;
        let minute_angle = minutes as f64 * one_minute_angle as f64;
        let hour_angle = ((hour % 12) as f64 * one_hour_angle as f64)
            + (minutes as f64 * (one_hour_angle as f64 / 60.0));
        let mut diff = hour_angle - minute_angle;
        diff = diff.abs();
        diff.min(360.0 - diff)
    }
}