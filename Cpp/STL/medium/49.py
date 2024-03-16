from typing import List

def groupAnagrams(strs: List[str]) -> List[List[str]]:
    ans = []
    newarr = []
    for i in range(len(strs)):
        string = "".join(sorted(strs[i]))
        newarr.append(string)
    # print(newarr)
    d = {}
    for i in range(len(newarr)):
        if newarr[i] not in d:
            d[newarr[i]] = [strs[i]]
        else:
            d[newarr[i]].append(strs[i])
    

    return list(d.values())


strs = ["eat","tea","tan","ate","nat","bat"]
print(groupAnagrams(strs))