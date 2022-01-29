from typing import List
from collections import namedtuple
from bisect import bisect_left

""" Given an array of integers nums and an integer target,
    return indices of the two numbers such that they add up to target.
"""
def twoSum(nums: List[int], target: int) -> List[int]:
    #O(n^2) implementation
    sz = len(nums)
    """
    for i in range(sz):
        for j in range(sz):
            if i != j:
                if nums[i] + nums[j] == target:
                    return [i,j]
    """
    Node = namedtuple('Node',['index', 'value'])
    nodeList = []
    for i in range(sz):
        nodeList.append(Node(i,nums[i]))
    #sort the list
    nodeList.sort(key = lambda x: x.value)

    for i in range(sz-1):
        rem = target - nodeList[i].value
        found = bsearch(nodeList, rem)
        if found == None :
            continue
        else :
            return [nodeList[i].index, found.index]
            
    return [-1,-1]

#helper
def bsearch(nodeList, val):
    s = 0;
    e = len(nodeList) - 1
    while s <= e:
        m = int((s + e) /2)
        if nodeList[m].value == val:
            return nodeList[m]
        elif nodeList[m].value > val:
            e = m - 1
        else:
            s = m + 1
    return None

if __name__ == '__main__':
    x = twoSum([11,12,3,14,5,16,7,18,9], 29)
    print(x)