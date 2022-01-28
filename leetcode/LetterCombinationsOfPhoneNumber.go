package main

import "fmt"

func letterCombinations(digits string) []string {
	var ans []string
	if digits == "" {
		return ans
	}
	nums := make(map[int]string)
	nums[2] = "abc"
	nums[3] = "def"
	nums[4] = "ghi"
	nums[5] = "jkl"
	nums[6] = "mno"
	nums[7] = "pqrs"
	nums[8] = "tuv"
	nums[9] = "wxyz"
	ans = []string{""}
	for i := range digits {
		strNums := nums[int(digits[i]-'0')]
		var res []string
		for j := range strNums {
			for curAns := range ans {
				//fmt.Println(res)
				res = append(res, ans[curAns]+string(strNums[j]))
			}
		}
		ans = res
	}
	return ans
}

func main() {
	digits := "23"
	fmt.Println(letterCombinations(digits))
}
