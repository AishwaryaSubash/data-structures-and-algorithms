from typing import List

def longestConsecutive(nums: List[int]) -> int:
    if len(arr) == 0:
        return 0
    arr = list(set(nums))

    arr.sort()
    print(arr)

    max_count = 0
    count = 0
    for i in range(len(arr)-1):
        if arr[i+1]==arr[i]+1:
            count += 1
            if max_count<count:
                max_count = count
        else:
            count = 0
            if max_count<count:
                max_count = count
    return max_count+1

    

nums = [0,3,7,2,5,8,4,6,0,1]
print(longestConsecutive(nums))