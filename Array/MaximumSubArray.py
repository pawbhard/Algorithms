"""
Given an integer array nums,
find the contiguous subarray
(containing at least one number)
which has the largest sum and return its sum.
"""

def maxSubArray(nums):
    max_sum = -1000000
    sum = 0
    for i in range(0, len(nums)):
        sum += nums[i]
        if sum > max_sum:
            max_sum = sum
        
        if sum < 0:
            sum = 0
        
            
    return max_sum

if __name__ == '__main__':
    #print(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
    print(maxSubArray([-2,-10,-3,-4,-1,-2,-11,-5,-4]))
    print(maxSubArray([5,4,-1,7,8]))
    print(maxSubArray([1]))