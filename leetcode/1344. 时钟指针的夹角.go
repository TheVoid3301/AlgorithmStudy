func angleClock(hour int, minutes int) float64 {
	const oneMinuteAngle = 6.0
	const oneHourAngle = 30.0

	// 分针角度
	minuteAngle := float64(minutes) * oneMinuteAngle

	// 时针角度：基础小时角度 + 分钟带来的偏移
	hourAngle := float64(hour%12)*oneHourAngle + float64(minutes)*(oneHourAngle/60.0)

	// 计算夹角差值的绝对值
	diff := math.Abs(hourAngle - minuteAngle)

	// 返回最小夹角
	if diff < 360.0-diff {
		return diff
	}
	return 360.0 - diff
}