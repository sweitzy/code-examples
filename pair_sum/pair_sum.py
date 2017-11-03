#!/usr/bin/env python3

# pair_sum.py

# See https://www.youtube.com/watch?v=XKu_SEDAykw

# Search for pair of numbers in a list that adds to a specific sum.

def has_pair_with_sum(data, sum):
    """Return True if two numbers in data add up to sum

    BIG O: O(n)

    >>> print(has_pair_with_sum([1, 2, 3, 4], 8))
    False
    >>> print(has_pair_with_sum([1, 2, 4, 4], 8))
    True
    """

    # I prefer to use dict() instead of {}
    seen = dict()

    for value in data:
        if (sum - value) in seen:
            return True
        else:
            seen[value] = 1
    return False


# validate documentation tests
if __name__ == '__main__':
#    print(has_pair_with_sum([1, 2, 3, 4], 8))
#    print(has_pair_with_sum([1, 2, 4, 4], 8))

    print('Entering main, running doctest.')
    import doctest
    doctest.testmod()

