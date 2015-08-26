package main

import (
	"fmt"
	"math/big"
)

func main() {
	var n int
	fmt.Scan(&n)
	var sum = big.NewInt(0)

	for i := 0; i < n; i++ {
		var newNum int
		fmt.Scan(&newNum)
		sum.Add(big.NewInt(int64(newNum)), sum)
	}

	fmt.Println(sum)
}
