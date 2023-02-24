a = input()
b = input()
x = {}
y = {}
for i in range(len(a)):
    for j in range(len(b)):
        if (a[i] == b[j]) and (a[i] not in x):
            x[a[i]] = i
            y[b[j]] = j
print(x, y)
count = 0
for i in x:
    if i in y:
        if x[i] >= y[i]:
            count += 1
print(count)
