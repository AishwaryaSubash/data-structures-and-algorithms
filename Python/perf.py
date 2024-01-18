l=[]
def perf(n):
    sum=0
    for i in range(1,n):  
        if n%i==0:
            sum+=i
    return sum

for num in range(1,1001):
    ans = perf(num)
    if ans==num:
        l.append(num)
print(l)