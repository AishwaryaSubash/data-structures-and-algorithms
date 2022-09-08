s = input()
n = int(input().strip())
acount = 0
def count(s):
    global acount
    for c in s:
        if c=='a':
            acount+=1
count(s)

acount= acount*(n//len(s))
run = n%len(s)

mul = s[:run]
count(mul)

print(acount)


# mul = s * n
# print(mul)
# while True:
#     if len(s)%n==0:



# mul = mul[:n]
# count = 0
# for i in mul:
#     if i=='a':
#         count+=1
# print(count)