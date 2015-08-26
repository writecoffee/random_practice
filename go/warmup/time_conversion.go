package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string

	fmt.Scan(&input)
	format := input[strings.Index(input, "M")-1 : len(input)]
	input = input[0 : strings.Index(input, "M")-1]
	items := strings.Split(input, ":")

	notFormatted, _ := strconv.Atoi(items[0])
	notFormatted = notFormatted % 12

	if format == "PM" {
		items[0] = strconv.Itoa(notFormatted + 12)
	}

	for i, item := range items {
		if len(item) < 2 {
			items[i] = fmt.Sprint("0", item[i])
		}
	}

	fmt.Println(strings.Join(items, ":"))
}
