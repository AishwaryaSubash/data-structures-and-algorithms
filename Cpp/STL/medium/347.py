from typing import List

def topKFrequent(nums: List[int], k: int) -> List[int]:
    ans = []
    d = {}
    for item in nums:
        if item not in d:
            d[item] = 1
        else:
            d[item] += 1

    # print(d)
    final = list(d.values())
    final.sort(reverse=True)
    # print(final[:k])
    d = dict(sorted(d.items(), key=lambda item: item[1],reverse=True))
    while k>0:
        for ind in final[:k+1]:
            print(ind)
        k -= 1
    return ans


nums = [1,1,1,2,2,3]
k = 2
print(topKFrequent(nums, k))