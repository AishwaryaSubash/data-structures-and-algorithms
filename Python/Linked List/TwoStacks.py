def whatFlavors(cost, money):
    pass

t = int(input().strip())
for t_itr in range(t):
    money = int(input().strip())
    n = int(input().strip())
    cost = list(map(int, input().rstrip().split()))
    whatFlavors(cost, money)
