package main

import (
	"fmt"
)

func main() {
	var n int
	var sum = 0

	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		var t int
		fmt.Scan(&t)
		sum += t
	}

	fmt.Println(uint(sum))
}
