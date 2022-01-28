package main

//https://leetcode.com/problems/3sum-closest/
import (
	"fmt"
	"sort"
)

const maxn = 1000001

type data struct {
	id1 int
	id2 int
	val int
}

type id struct {
	id1 int
	id2 int
}

func remove(s []int, i int) []int {
	s[i] = s[len(s)-1]
	return s[:len(s)-1]
}
func threeSum(nums []int) [][]int {
	var result [][]int
	if len(nums) < 3 {
		return result
	}

	sort.Ints(nums)
	for i := 0; i < len(nums); i++ {
		if i != 0 && nums[i-1] == nums[i] {
			continue
		}

		for k, j := i+1, len(nums)-1; k < j; {
			n := nums[i] + nums[k] + nums[j]
			if n == 0 {
				result = append(result, []int{nums[i], nums[k], nums[j]})
				l := k
				for l < j && nums[l] == nums[k] {
					l++
				}
				k = l
			} else if n > 0 {
				j--
			} else {
				k++
			}
		}
	}
	return result
}
func main() {
	nums := []int{-1, 0, 1, 2, -1, -4}
	fmt.Println(threeSum(nums))
}
