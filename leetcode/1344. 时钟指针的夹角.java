class Solution {
    public double angleClock(int hour, int minutes) {
        final double oneMinuteAngle = 6.0;
        final double oneHourAngle = 30.0;
        
        // 分针角度
        double minuteAngle = minutes * oneMinuteAngle;
        
        // 时针角度：基础小时角度 + 分钟带来的偏移
        double hourAngle = (hour % 12) * oneHourAngle + minutes * (oneHourAngle / 60.0);
        
        // 计算夹角差值的绝对值
        double diff = Math.abs(hourAngle - minuteAngle);
        
        // 返回最小夹角
        return Math.min(diff, 360.0 - diff);
    }
}