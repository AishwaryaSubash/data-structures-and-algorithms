arr = []
for _ in range(6):
    arr.append(list(map(int, input().rstrip().split())))
a=[]
for i in range(1,5):
    for j in range(1,5):
        e=(arr[i-1][j-1]+arr[i-1][j]+arr[i-1][j+1]+arr[i][j]+arr[i+1][j-1]+arr[i+1][j]+arr[i+1][j+1])
        a.append(e)
print(max(a))