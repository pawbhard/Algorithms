"""
Find Minimum in Rotated Sorted Array
"""

def findMin(nums) -> int:
    low = 0
    high = len(nums) - 1

    while low < high:
        mid = (high + low)//2

        if nums[mid] == nums[high]:
            high -= 1
        elif nums[mid] > nums[high]:
            low = mid + 1
        else:
            high = mid

    return nums[high]



if __name__ == '__main__':
    print(findMin([8,9,5,6,7]))
    print(findMin([5,6,7,8,9]))
    print(findMin([6,7,8,9,5]))
    print(findMin([16,7]))
    print(findMin([6,6,6,6,6,11]))
