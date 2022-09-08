def check():
    global valley
    if flag==0:
        valley+=1

steps = int(input("num "))
path = input("Path : ")

path = path[:steps]
# print(path)
flag = 0
valley = 0

for step in path:
    if step=='U':
        flag += 1
        check()
    elif step=='D':
        flag-=1

print(valley, flag)