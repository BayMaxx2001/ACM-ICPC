package main

import "math"

func maximumScore(nums []int, k int) int {
	if len(nums) == 1 {
		return nums[0]
	}
	min := nums[k]
	i := k
	j := k
	ans := 0
	for i > 0 || j < len(nums)-1 {
		if i == 0 {
			j++
		} else if j == len(nums)-1 {
			i--
		} else if nums[i-1] < nums[j+1] {
			j++
		} else {
			i--
		}
		min = int(math.Min(float64(min), math.Min(float64(nums[i]), float64(nums[j]))))
		if ans < min*(j-i+1) {
			ans = min * (j - i + 1)
		}
	}
	return ans
}
