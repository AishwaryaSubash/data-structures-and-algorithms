n = int(input("n "))
c = list(map(int, input().rstrip().split()))
c = c[:n]
# print(c)
jump = 0
i=0
nos = n
while n>=3:
    if c[i+2] == 0:
        jump+=1
        i+=2
        n-=2
    elif c[i+1] == 0:
        jump+=1
        i+=1
        n-=1    
    else:
        break

if n == 2:
    jump += 1

print(jump)