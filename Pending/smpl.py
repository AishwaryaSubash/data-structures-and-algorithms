m = int(input())
s= input()
l = s.split()
n = int(input())

d={}
for i in l:
    if i not in d:
        d[i]=1
    else:
        d[i]+=1
print(d)
max=-1
for i in d:
    if d[i]>=n:
        print(i)
#####################################
for i in range(len(d)):
    for j in range(len(d)):
        if d[i]<d[j]:
            temp=d[i]
            d[i]=d[j]
            d[j]=temp
for i in d:
    print(i)

