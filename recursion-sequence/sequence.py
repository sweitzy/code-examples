#!/usr/bin/python

# sequence.py

# Please solve: Take two numbers, second number greater than the first,
# as input say 3 and 7 and print the sequence as follows using
# recursion: 3 4 5 6 7 6 5 4 3 Recursion involves calling the same
# function recursively until some condition is met.

def sequence(lower, upper):
    """sequence: recursive function to print a number sequence"""

    if lower > upper:
        # invalid case 
        return
    elif lower == upper:
        # we are at peak of sequence
        print(upper, end=" ");
    else:
        print(lower, end=" ")
        # recurse toward upper
        sequence(lower + 1, upper)
        print(lower, end=" ")
