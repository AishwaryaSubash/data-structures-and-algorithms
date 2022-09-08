def alternatingCharacters(s):
    c = 0
    prev = s[0]
    for i in s[1:]:
        if prev == i:
            #print(prev,i)
            c += 1
        prev = i

    return c

q = int(input().strip())

for i in range(q):
    s = input()
# s = "ABABABBBAAAAAAAAAAAAAAAAAAA"
# result = alternatingCharacters(s)
# print(result)
