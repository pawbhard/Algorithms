
def productSelf(nums):
    product = 1
    out = []

    for n in nums:
        product *= n
    
    for n in nums:
        out.append(int(product / n))
    
    return out

if __name__ == '__main__':
    print(productSelf([2,3,4,6]))