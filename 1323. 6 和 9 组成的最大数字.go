func maximum69Number(num int) int {
	numstr := strconv.Itoa(num)
	result := ""
	found := false
	for _, ch := range numstr {
		if !found && ch == '6' {
			result += "9"
			found = true
		} else {
			result += string(ch)
		}
	}
	res, _ := strconv.Atoi(result)
	return res
}