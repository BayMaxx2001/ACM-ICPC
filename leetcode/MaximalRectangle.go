package main

func maximalRectangle(matrix [][]byte) int {
	row := len(matrix)
	col := len(matrix[0])
	if row == 0 {
		return 0
	}
	ans := 0
	arr := make([]int, col)
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if matrix[i][j] == '0' {
				arr[j] = 0
			} else {
				arr[j] = arr[j] + 1
			}
		}

		S := calc(arr)
		if S > ans {
			ans = S
		}
	}
	return ans
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
