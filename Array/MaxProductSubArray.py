"""
Given an integer array nums, find a contiguous non-empty subarray
within the array that has the largest product, and return the product.
"""

def maxProduct(nums) -> int:
    maxVal = nums[0]
    minVal = nums[0]

    maxProd = nums[0]

    for i in range(1,len(nums)):
        if maxVal == None:
            maxVal = nums[i]
            minVal = nums[i]
        
        if nums[i] < 0:
            maxVal,minVal = minVal, maxVal

        
        maxVal = max(nums[i], maxVal * nums[i])
        minVal = min(nums[i], minVal * nums[i])
        
        maxProd = max(maxProd, maxVal)
    
    return maxProd


if __name__ == '__main__':
    print(maxProduct([1,2,-3,4]))
    print(maxProduct([1,-2,-3,4]))
    print(maxProduct([1,2,0,-3,4]))
    print(maxProduct([1,-2,-8,0,-3,4]))
    print(maxProduct([1,-2,-8,0,-3,4,-9]))
