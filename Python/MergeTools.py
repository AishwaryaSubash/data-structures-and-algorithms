s = input("S :")
k = int(input("K : "))
n = len(s)/k
l = []
s = s.upper()
for i in range(0, len(s), k):
    m = []
    string = ""
    for j in s[i:i+k]:
        if j not in m:
            m.append(j)
    for j in m:
        string = string + j
    l.append(string)

for i in l:
    print(i)