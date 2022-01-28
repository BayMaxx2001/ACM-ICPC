package main

func firstMissingPositive(nums []int) int {
	MAP := make(map[int]int)
	max := 2147483649
	for i := 0; i < len(nums); i++ {
		if nums[i] > 0 {
			MAP[nums[i]]++
		}

	}
	for i := 1; i <= max; i++ {
		if MAP[i] == 0 {
			return i
		}
	}
	return 0
}

func main() {

}
