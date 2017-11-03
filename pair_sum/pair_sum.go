package main

import "fmt"

// pair_sum.py

// See https://www.youtube.com/watch?v=XKu_SEDAykw

// Search for pair of numbers in a list that adds to a specific sum.

func has_pair_with_sum(data []int, sum int) bool {

	seen := make(map[int]bool)

	for _, value := range data {
		_, ok := seen[sum - value]
		if ok {
			return true
		} else {
			seen[value] = true
		}
	}
	return false
}

func main() {
	fmt.Println("Entering main.")

	fmt.Println(has_pair_with_sum([]int{1, 2, 3, 9}, 8))
	fmt.Println(has_pair_with_sum([]int{1, 2, 4, 4}, 8))
}

