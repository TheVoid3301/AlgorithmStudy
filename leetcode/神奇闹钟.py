import os
import sys

from datetime import datetime, timedelta

def find_last_alarm(target_time_str, x_minutes):
    # 解析输入的时间字符串为datetime对象
    target_time = datetime.strptime(target_time_str, "%Y-%m-%d %H:%M:%S")
    # 计算目标时间与epoch时间的timedelta
    epoch = datetime(1970, 1, 1, 0, 0, 0)
    delta = target_time - epoch
    total_seconds = delta.total_seconds()
    total_minutes = int(total_seconds // 60)
    
    # 计算最近的闹钟响铃的间隔数
    intervals = total_minutes // x_minutes
    last_alarm_minutes = intervals * x_minutes
    last_alarm_seconds = last_alarm_minutes * 60
    
    # 将秒数转换回datetime
    last_alarm_time = epoch + timedelta(seconds=last_alarm_seconds)
    
    # 格式化为字符串
    return last_alarm_time.strftime("%Y-%m-%d %H:%M:%S")

T = int(input())
for _ in range(T):
    line = input().strip()
    # 分割时间和x
    # 时间格式是yyyy-MM-dd HH:mm:ss x
    parts = line.rsplit(' ', 1)
    time_str = parts[0]
    x = int(parts[1])
    print(find_last_alarm(time_str, x))