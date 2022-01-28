package main

func largestRectangleArea(heights []int) int {
	return calc(heights)
}
func calc(arr []int) int {
	var stack []int
	max := 0
	for i := 0; i <= len(arr); i++ {
		var cur int
		if i == len(arr) {
			cur = -1
		} else {
			cur = arr[i]
		}

		for len(stack) != 0 && cur < arr[stack[len(stack)-1]] {
			w := arr[stack[len(stack)-1]]
			stack = stack[:len(stack)-1]
			var h int
			if len(stack) == 0 {
				h = i
			} else {
				h = i - stack[len(stack)-1] - 1
			}
			area := w * h
			if area > max {
				max = area
			}
		}
		stack = append(stack, i)
	}
	return max
}
func main() {

}
