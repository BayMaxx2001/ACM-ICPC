package main

func uniquePaths(m int, n int) int {
	ans := make([][]int, m+1)

	for idx := range ans {
		ans[idx] = make([]int, n+1)
	}
	for i := 0; i < n; i++ {
		ans[0][i] = 1
	}

	for i := 0; i < m; i++ {
		ans[i][0] = 1
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			ans[i][j] = ans[i-1][j] + ans[i][j-1]
		}
	}
	return ans[m-1][n-1]
}
