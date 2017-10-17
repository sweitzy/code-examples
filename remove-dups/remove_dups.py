#!/usr/bin/env python3

# remove_dups.py
#   NOTE: have to use underscore for import to work

# Original question: write a function to return a copy of a list with duplicates removed

def remove_dups(elems):
    """Remove duplicate elems from a group of elements.

    Return uniq elements in the order they first appear.

    >>> print(remove_dups([2, 4, 5, 2, 5, 7, 2, 5, 6]))
    [2, 4, 5, 7, 6]

    >>> print(remove_dups(["a", "a", "b", "a", "c"]))
    ['a', 'b', 'c']
    """

    # list of unique elements
    output = []

    # elements we have seen so far, for quick lookup
    seen = {}

    # BIG O:
    #  O(n) to walk elems
    #  O(1) to look up in dictionary

    # TODO: can we use a list comprehension?

    for elem in elems:
        # if elem not read already, append elem and mark as seen
        if not elem in seen:
            output.append(elem)
            seen[elem] = 1

    return output


# Second question: return the mth duplicate

def collapse_dups(elems, m):
    """Remove duplicate elems from a group of elements, using the mth occurence.

    Return uniq elements in the order they appear the mth time.

    >>> print(collapse_dups([2, 4, 5, 2, 5, 7, 2, 5, 6], 1))
    [2, 4, 5, 7, 6]
    >>> print(collapse_dups([2, 4, 5, 2, 5, 7, 2, 5, 6], 2))
    [4, 2, 5, 7, 6]
    >>> print(collapse_dups([2, 2, 4, 5, 2, 5, 7, 2, 5, 6, 2], 1))
    [2, 4, 5, 7, 6]
    >>> print(collapse_dups([2, 2, 4, 5, 2, 5, 7, 2, 5, 6, 2], 3))
    [4, 2, 7, 5, 6]
    """

    # list of unique elements
    output = []

    # elements we have seen so far, for quick lookup
    seen = {}

    # place where each element is in output
    place = {}

    # BIG O:
    #  O(n) to walk elems
    #  O(1) to look up in dictionary
    #  O(n) to shift output

    for elem in elems:
        # if elem not read already, append elem and mark as seen
        if not elem in seen:
            output.append(elem)
            seen[elem] = 1
            place[elem] = len(output) - 1
#            print('DEBUG: first time', output)
        else:
            seen[elem] += 1
            if seen[elem] <= m:
#                print('DEBUG: have seen', elem, ', deleting ', place[elem])
                del(output[place[elem]])
#                print('DEBUG: output1 now', output)
                # we have to rebuild place
                for x in range(place[elem], len(output)):
#                    print('DEBUG: rebuild', x)
                    place[output[x]] = x
                output.append(elem)
                place[elem] = len(output) - 1
#                print('DEBUG: output2 now', output)

    return output

# validate documentation tests
if __name__ == '__main__':
    first = [2, 4, 5, 2, 5, 7, 2, 5, 6]

    print('Entering main, running doctest.')
    import doctest
    doctest.testmod()
