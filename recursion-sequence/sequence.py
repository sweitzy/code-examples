#!/usr/bin/python

# sequence.py

# Please solve: Take two numbers, second number greater than the first,
# as input say 3 and 7 and print the sequence as follows using
# recursion: 3 4 5 6 7 6 5 4 3 Recursion involves calling the same
# function recursively until some condition is met.

def sequence(lower, upper):
    """Print a number sequence using recursion.

    Print from lower to upper and back down again.
    """

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

def sequence2(lower, upper):
    """Return list of a number sequence using recursion.

    Build from lower to upper and back down again.
    """

    if lower > upper:
        # invalid case 
        return []
    elif lower == upper:
        # we are at peak of sequence
        return [upper]
    else:
        return [lower] + sequence2(lower + 1, upper) + [lower]
