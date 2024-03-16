from typing import List

def productExceptSelf(nums: List[int]) -> List[int]:
    left = [1]
    right = [1]*len(nums)
    
    for i in range(1,len(nums)):
        left.append(left[i-1]*nums[i-1])
    
    for i in range(len(nums)-2,-1,-1):
        right[i] = right[i+1]*nums[i+1]
    # print(left, right)

    ans = []
    for i in range(len(nums)):
        ans.append(left[i]*right[i])
    return ans
        

nums = [1,2,3,4]
print(productExceptSelf(nums))