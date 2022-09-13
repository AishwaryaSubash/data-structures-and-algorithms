def twoStrings(s1, s2):
    for i in s1:
        for j in s2:
            if i==j:
                return "YES"
    return "NO"

n = int(input().strip())
l=[]
for i in range(n):
    s1 = input()
    s2 = input()
    result = twoStrings(set(s1), set(s2))
    l.append(result)

for i in range(n):
    print(l[i])
