//https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/779/
package main

import "math"

func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
func lengthOfLongestSubstring(s string) int {

	Map := make(map[rune]int)
	longest := 0
	i := 0
	j := 0

	sli := []rune(s)

	for i < len(sli) && j < len(sli) {
		if val, ok := Map[sli[j]]; ok {
			longest = int(math.Max(float64(longest), float64(j-i)))
			i = int(math.Max(float64(i), float64(val+1)))
			Map[sli[j]] = j
			j++
		} else {
			Map[sli[j]] = j
			j++
		}
	}
	return int(math.Max(float64(longest), float64(j-i)))
}
