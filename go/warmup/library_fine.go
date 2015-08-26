package main

import (
	"fmt"
)

func main() {
	var dd, mm, yy int
	var exdd, exmm, exyy int

	fmt.Scan(&dd, &mm, &yy, &exdd, &exmm, &exyy)

	exDate := exyy*10000 + exmm*100 + exdd
	acDate := yy*10000 + mm*100 + dd

	var result uint
	if acDate <= exDate {
		result = 0
	} else if yy == exyy && mm == exmm {
		result = uint(15 * (dd - exdd))
	} else if yy == exyy {
		result = uint(500 * (mm - exmm))
	} else {
		result = 10000
	}

	fmt.Println(result)
}
