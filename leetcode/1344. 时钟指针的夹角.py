class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        one_minute_angle = 6.0
        one_hour_angle = 30.0
        
        # 分针角度
        minute_angle = minutes * one_minute_angle
        
        # 时针角度：基础小时角度 + 分钟带来的偏移
        hour_angle = (hour % 12) * one_hour_angle + minutes * (one_hour_angle / 60.0)
        
        # 计算夹角差值的绝对值
        diff = abs(hour_angle - minute_angle)
        
        # 返回最小夹角
        return min(diff, 360.0 - diff)