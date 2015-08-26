package main

import (
	"fmt"
	"math/big"
)

func main() {
	var num int64
	fmt.Scan(&num)
	var product = big.NewInt(1)
	product.MulRange(1, num)

	fmt.Println(product)
}
