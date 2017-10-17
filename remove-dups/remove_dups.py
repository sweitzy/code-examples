#!/usr/bin/env python3

# remove_dups.py
#   NOTE: have to use uderscore for import to work

# Original question: write a function to return a copy of a list with duplicates removed

# TODO: rename list_of_nums to sequence_of_nums since it can be list, tuple, what else???...

def remove_dups(list_of_nums):
    """Remove duplicate numbers from a list.

    Return list of numbers with duplicates removed.
    """

    # TODO: can I make this generic for any type?
    list_uniq = []

    # nums we have seen so far
    seen = {}

    # BIG O:
    #  O(n) to walk list_of_nums
    #  O(1) to look up in dictionary

    # TODO: use a list comprehension

    for num in list_of_nums:
        # if num not read already, append num and mark as seen
        if not num in seen:
            list_uniq.append(num)
            seen[num] = 1

    return list_uniq


# Second question: return the mth duplicate

def collapse_dups(list_of_nums, m):
    """Remove duplicate numbers from a list.

    Return list of numbers with duplicates removed.
    """

    # TODO: can I make this generic for any type?
    output = []

    # nums we have seen so far
    seen = {}

    # place where each num is in output
    place = {}

    # BIG O:
    #  O(n) to walk list_of_nums
    #  O(1) if dictionary is implemented efficiently (TODO: is it?)

    # TODO: use a list comprehension

    for num in list_of_nums:
        # if num not read already, append num and mark as seen
        if not num in seen:
            output.append(num)
            seen[num] = 1
            place[num] = len(output) - 1
            print("DEBUG: first time", output)
        else:
            seen[num] += 1
            if seen[num] <= m:
                print("DEBUG: have seen", num)
                del(output[place[num]])
                print("DEBUG: output now", output)
                # we have to rebuild place
                for x in range(place[num], len(output)):
                    print("DEBUG: rebuild", x)
                    place[output[x]] = x
                output.append(num)
                place[num] = len(output)

    return output

# TODO: use Python unit test ability to test this

# TODO: do we want anything in main?
if __name__ == "__main__":
    first = [2, 4, 5, 2, 5, 7, 2, 5, 6]

