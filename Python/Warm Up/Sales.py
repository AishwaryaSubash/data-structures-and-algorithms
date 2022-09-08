n = int(input().strip())
ar = list(map(int, input().rstrip().split()))
ar = ar[:n]
# print(n,ar)
sock = set(ar)
l = []
for s in sock:
    l.append(ar.count(s))

count = 0
for i in l:
    count += i//2
print(count)
        