package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	var v [][]int = make([][]int, n)
	for i := range v {
		v[i] = make([]int, n)
	}

	for i := 0; i < n*n; i++ {
		var number int
		fmt.Scan(&number)

		v[i/n][i%n] = number
	}

	var ldSum, rdSum int
	ldSum = 0
	rdSum = 0
	for i := 0; i < n; i++ {
		ldSum += v[i][i]
		rdSum += v[i][n-1-i]
	}

	fmt.Println(math.Abs(float64(ldSum - rdSum)))
}
