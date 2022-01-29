"""
Given an integer array nums,
return true if any value appears at least twice in the array,
and return false if every element is distinct.
"""

from typing import Set


def containsDuplicate(nums) -> bool:
    tmp = set ({})
    for n in nums:
        if n in tmp:
            return True
        tmp.add(n)
    return False

if __name__ == '__main__':
    print(containsDuplicate([1,2,3,5,6,12,9]))