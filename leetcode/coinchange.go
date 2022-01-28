package main

import (
	"fmt"
	"math"
)

func coinChange(coins []int, amount int) int {
	if amount < 0 {
		return -1
	}

	dp := make([]int, amount+1)
	dp[0] = 0
	for i := 1; i < amount+1; i++ {
		dp[i] = -1
	}

	for i := range coins {
		coin := coins[i]
		for i := 1; i <= amount; i++ {
			if i-coin >= 0 && dp[i-coin] != -1 {
				if dp[i] != -1 {
					dp[i] = int(math.Min(float64(dp[i]), float64(dp[i-coin]+1)))
				} else {
					dp[i] = dp[i-coin] + 1
				}
			}
		}
	}
	return dp[amount]
}
func main() {
	coins := []int{1, 2, 5}
	amount := 11
	fmt.Println(coinChange(coins, amount))
}
