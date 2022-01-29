"""
Find in Rotated Sorted Array
"""
def search(nums, val, l, h):
    if l > h:
        return -1
    
    m = (h + l) // 2
    if nums[m] == val:
        return m
    
    if nums[l] <= nums[m]:
        if val <= nums[m] and val >= nums[l]:
            return search(nums, val, l, m-1)
        else:
            return search(nums, val, m+1, h)
    else:
        if val >= nums[m] and val <= nums[h]:
            return search(nums, val, m+1, h)
        else:
            return search(nums, val, l, m-1)

def find(nums, val) -> int:
    return search(nums, val, 0, len(nums)-1)

if __name__ == '__main__':
    print(find([4,5,6,1,2],4))
    print(find([4,5,6,1,2,3],3))
    print(find([14,5],5))