package main

import (
	"fmt"
)

func main() {
	var n int

	fmt.Scan(&n)
	i, negCnt, posCnt, zeroCnt := 0, 0, 0, 0

	for ; i < n; i++ {
		var number int
		fmt.Scan(&number)

		if number < 0 {
			negCnt++
		} else if number == 0 {
			zeroCnt++
		} else {
			posCnt++
		}
	}

	negPercent := float32(negCnt) / float32(n)
	posPercent := float32(posCnt) / float32(n)
	zeroPercent := float32(zeroCnt) / float32(n)

	fmt.Printf("%.3f\n", posPercent)
	fmt.Printf("%.3f\n", negPercent)
	fmt.Printf("%.3f\n", zeroPercent)
}
