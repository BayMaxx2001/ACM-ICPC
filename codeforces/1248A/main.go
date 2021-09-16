package main

import (
	"bufio"
	"os"
	"fmt"
)
var (
	ans int64 
	n int
	m int
	save = make([]int, 3)

	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)


func solve(){
	save[0]=0
	save[1]=0
	ans = 0
	_, _ = fmt.Fscan(r, &n)
	for i:=1;i<=n;i++{
		var x int 
		_, _ = fmt.Fscan(r, &x)
		save[x%2]++
	}
	_, _ = fmt.Fscan(r, &m)
	for i:=1;i<=m;i++{
		var x int 
		_, _ = fmt.Fscan(r, &x)
		ans += (int64(save[x%2]))	
	}
	_, _ = fmt.Println(int64(ans))
}
func main(){
	defer w.Flush()
	var te int 
	_, _ = fmt.Fscan(r, &te)
	for i := 1; i <= te; i++{
		solve()
	}
}