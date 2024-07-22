from typing import List

def twoSum(numbers: List[int], target: int, kk: int) -> List[int]:
    if len(numbers) == 0:
        return []
    
    # Akash's code
    # d = {}
    # ans = []
    # for i in range(len(nums)):
    #     num = target - nums[i]
    #     if d.get(num) == None:
    #         d[nums[i]] = i
    #     else:
    #         ans.append(sorted([num, nums[i], kk]))
    # return ans

    d = {}
    for i in range(len(numbers)):
        d[numbers[i]] = i

    print(numbers, target)
    print(d)
    
    for num in numbers:
        if d.get(target-num) != None and d.get(num) != d.get(target-num):
            return [num, target-num]
    return []


def threeSum(nums: List[int]) -> List[List[int]]:
    arr = []
    for i in range(len(nums)):
        ans = [nums[i]]
        ans.extend(twoSum(nums[i+1:], 0 - nums[i], i+1))
        ans.sort()
        print(ans)
        print("\n")
        if len(ans) == 3 and ans not in arr:
            arr.append(ans)
    return arr
        
        
nums = [1,2,-2,-1]
print(threeSum(nums))