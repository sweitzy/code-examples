#!/usr/bin/env tclsh

# sequence.tcl

# Please solve: Take two numbers, second number greater than the first,
# as input say 3 and 7 and print the sequence as follows using
# recursion: 3 4 5 6 7 6 5 4 3 Recursion involves calling the same
# function recursively until some condition is met.

proc sequence {lower upper} {
    if {$lower > $upper} {
        # invalid case 
        return
    } elseif {$lower == $upper} {
        # we are at peak of sequence
        puts $upper
    } else {
	puts $lower
        # recurse toward upper
        sequence [expr $lower + 1] $upper
        puts $lower
    }
}

proc sequence2 {lower upper} {
    if {$lower > $upper} {
        # invalid case 
        return
    } elseif {$lower == $upper} {
        # we are at peak of sequence
        return $upper
    } else {
	return "$lower [sequence2 [expr $lower + 1] $upper] $lower"
    }
}

sequence 3 7
puts [sequence2 3 7]

