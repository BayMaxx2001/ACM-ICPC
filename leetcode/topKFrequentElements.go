package main

import (
	"fmt"
	"sort"
)

type data struct {
	val int
	cnt int
}

func topKFrequent(nums []int, k int) []int {
	Map := make(map[int]int)
	var save []data
	var ans []int
	for i := 0; i < len(nums); i++ {
		Map[nums[i]]++
		if Map[nums[i]] == 1 {
			cur := data{nums[i], 0}
			save = append(save, cur)
		}
	}

	for i := 0; i < len(save); i++ {
		save[i].cnt = Map[save[i].val]
	}
	sort.Slice(save, func(i, j int) bool {
		return save[i].cnt >= save[j].cnt
	})

	for i := 0; i < k; i++ {
		fmt.Println(save[i].val, save[i].cnt)
		ans = append(ans, save[i].val)
	}
	return ans
}

func main() {
	nums := []int{1, 1, 1, 2, 2, 3}
	k := 2
	fmt.Println(topKFrequent(nums, k))
}
