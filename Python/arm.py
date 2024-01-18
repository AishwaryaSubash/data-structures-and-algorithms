def arm(n):
    size = len(str(n))
    sum=0
    while n>0:
        digit = n%10
        sum+=digit**size
        n = n//10
    return sum
    
lower = int(input("lower: "))
upper = int(input("upper: "))
l=[]
for num in range(lower, upper+1):
    ans = arm(num)
    if ans == num:
        l.append(num)
print(l)