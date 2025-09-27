func largestPerimeter(nums []int) int {
	sort.Ints(nums)
	for i := 1; i <= len(nums)-2; i++ {
		if nums[len(nums)-i] < nums[len(nums)-i-1]+nums[len(nums)-i-2] {
			return nums[len(nums)-i] + nums[len(nums)-i-1] + nums[len(nums)-i-2]
		}
	}
	return 0
}