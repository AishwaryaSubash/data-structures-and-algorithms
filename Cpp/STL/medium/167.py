from typing import List

def twoSum(numbers: List[int], target: int) -> List[int]:
    if len(numbers) == 0:
        return []

    left = 0
    right = len(numbers) - 1
    while left<=right:
        if numbers[left]+numbers[right] == target:
            return [left+1, right+1]
        elif numbers[left]+numbers[right] > target:
            right -= 1
        elif numbers[left]+numbers[right] < target:
            left += 1
        
        # if target>n umbers[]


numbers = [-1, 0]
target = -1
print(twoSum(numbers, target))