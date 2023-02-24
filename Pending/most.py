

p = input()
l = []
s = ""
b = eval(input())
for i in p:
    if not i.isalpha():
        if i != " ":
            s += " "
        s+=" "
    else:
        s += i
l= s.lower().split()
d={}
for word in l:
    if word not in b:
        if word not in d:
            d[word] = 1
        else:
            d[word]+=1
max=0
