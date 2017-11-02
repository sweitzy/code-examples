package main

import "fmt"

// Please solve: Take two numbers, second number greater than the first,
// as input say 3 and 7 and print the sequence as follows using
// recursion: 3 4 5 6 7 6 5 4 3 Recursion involves calling the same
// function recursively until some condition is met.

// sequence: recursive function to print a number sequence
func sequence(lower, upper int) {

        // this version uses if/else

	if lower > upper {
		// invalid case 
		return
	} else if lower == upper {
		// we are at peak of sequence
		fmt.Print(upper, " ")
	} else {
		fmt.Print(lower, " ")
		// recurse toward upper
		sequence(lower + 1, upper)
		fmt.Print(lower, " ")
	}
}

// sequence2: recursive function to print a number sequence
func sequence2(lower, upper int) {

        // this version uses switch

	switch {
	case lower > upper:
		// invalid case 
		return
	case lower == upper:
		// we are at peak of sequence
		fmt.Print(upper, " ")
	default: 
		fmt.Print(lower, " ")
		// recurse toward upper
		sequence(lower + 1, upper)
		fmt.Print(lower, " ")
	}
}

// sequence3: recursive function to return a number sequence
func sequence3(lower, upper int) {

	if lower > upper {
		// invalid case 
		return
	} else if lower == upper {
		// we are at peak of sequence
		fmt.Print(upper, " ")
	} else {
		fmt.Print(lower, " ")
		// recurse toward upper
		sequence(lower + 1, upper)
		fmt.Print(lower, " ")
	}
}

func main() {
	sequence(3, 7)
	fmt.Println()

	sequence2(3, 7)
	fmt.Println()
}

