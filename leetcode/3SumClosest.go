//https://leetcode.com/problems/3sum-closest/

package main

import (
	"fmt"
	"sort"
)

func abs(num int) int {
	if num < 0 {
		return -1 * num
	}
	return num
}
func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	ans := 1000000007
	fmt.Println(nums)
	for i := 0; i < len(nums)-2; i++ {
		k := len(nums) - 1
		j := i + 1
		for j < k {
			sum := nums[i] + nums[j] + nums[k]
			if sum == target {
				return sum
			}

			if abs(target-sum) < abs(target-ans) {
				ans = sum
			}
			if sum < target {
				j++
			} else {
				k--
			}
		}
	}
	return ans
}

func main() {
	nums := []int{0, 2, 1, -3}
	target := 1
	fmt.Println(threeSumClosest(nums, target))
}
