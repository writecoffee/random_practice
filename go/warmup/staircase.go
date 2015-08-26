package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	var buffer bytes.Buffer

	for i := 0; i < n; i++ {
		buffer.WriteString(strings.Repeat(" ", n-1-i))
		buffer.WriteString(strings.Repeat("#", i+1))
		buffer.WriteString("\n")
	}

	fmt.Print(buffer.String())
}
