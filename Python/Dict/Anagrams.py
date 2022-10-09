l = []
def get_permutation(string, i=0):
    if i == len(string):   	 
        l.append("".join(string))
    for j in range(i, len(string)):
        words = [c for c in string]
        # swap
        words[i], words[j] = words[j], words[i]
        get_permutation(words, i + 1)

def sherlockAndAnagrams(s):
    n = len(s)
    d = {}
    count = 0
    for i in range(n):
        for j in range(i, n):
            str1 = s[i:j+1]
            get_permutation(str1)
            flag = 0
            for k in range(len(l)):
                if l[k] in d:
                    d[l[k]] += 1
                    flag = 1
            if flag == 0:
                d[str1] = 1
            l.clear()
    for i in d.values():
        if i > 1:
            count +=1
    return count

q = int(input().strip())
ans = []
for i in range(q):
    s = input()
    result = sherlockAndAnagrams(s)
    ans.append(result)
for i in ans:
    print(i)