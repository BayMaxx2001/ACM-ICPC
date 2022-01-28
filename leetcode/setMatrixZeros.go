package main

//https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/777/
func setZeroes(matrix [][]int) {
	R := len(matrix)
	C := len(matrix[0])

	rows := make(map[int]int)
	cols := make(map[int]int)
	for i := 0; i < R; i++ {
		for j := 0; j < C; j++ {
			if matrix[i][j] == 0 {
				rows[i]++
				cols[j]++
			}
		}
	}

	for i := 0; i < R; i++ {
		for j := 0; j < C; j++ {
			if rows[i] != 0 || cols[j] != 0 {
				matrix[i][j] = 0
			}
		}
	}

}
