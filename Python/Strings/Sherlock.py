def valid(d):
    a = list(d.values())
    b=[]
    for i in range(len(a)-1):
        if a[i]!=0:
            b.append(a[i])
    print(b)
    
    mini = min(b)
    maxi= max(b)

    if mini == maxi:
        return True
    # elif mini==0:
    #     print(d)
    #     del d[list(d.values()).index(mini)]
    #     valid(d)
    # elif maxi==0:
    #     print(d)
    #     del d[list(d.values()).index(maxi)]
    #     valid(d)
    else:
        return False

s = input()
# result = isValid(s)

d = {}
for c in s:
    if c not in d:
        d[c] = 1
    else:
        d[c] += 1
res = valid(d)
count = {}
if res:
    print("YES")


else:
    for i in list(d.values()):
        if i not in count:
            count[i] = 1
        else:
            count[i] += 1
    # print(count)
    maxi = max(list(count.keys()))
    mini = min(list(count.keys()))
    #print(max, min)
    v = list(d.values())
    k = list(d.keys())
    delete = k[v.index(maxi)]
    d[delete] -= 1
    #print(d)
    
    if valid(d):
        print("YES")
    else:
        d[delete] += 1
        delete = k[v.index(mini)]
        d[delete] -= 1
        
        if valid(d):
            print("YES")
        else:
            d[delete] += 1
            print("NO")
# print(d)
