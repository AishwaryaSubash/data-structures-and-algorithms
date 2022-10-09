#Varala

def isSubsetSum(set, n, sum) :
    
    # Base Cases
    if (sum == 0) :
        return True
    if (n == 0 and sum != 0) :
        return False
    
    # If last element is greater than
    # sum, then ignore it
    if (set[n - 1] > sum) :
        return isSubsetSum(set, n - 1, sum)     
    # else, check if sum can be obtained
    # by any of the following
    # (a) including the last element
    # (b) excluding the last element   
    return isSubsetSum(set, n-1, sum) or isSubsetSum(set, n-1, sum-set[n-1])




def whatFlavors(cost, money):
    index = []
    cmon = money

    for i in list(range(1, money + 1)):
        if i < money:
            for j in range(len(cost)):
                if i == cost[j]:
                    if cmon >= cost[j]:
                        cmon -= cost[j]
                        index.append(j)
                    else:
                        break
        elif i == money:
            pass
    print(index,cmon)

# def whatFlavors(cost, money):
#     temp,result = money,0
#     # Pick starting point
#     for i in range(1, money):
 
#         # Pick ending point
#         temp=0
#         for j in range(i, money):
#             # sum subarray between
#             # current starting and
#             # ending points
#             temp+=cost[j]
#             result += temp
#     print(result)
        

t = int(input().strip())
for i in range(t):
    money = int(input().strip())
    n = int(input().strip())
    cost = list(map(int, input().rstrip().split()))
    whatFlavors(cost, money)
    if (isSubsetSum(set, n, sum) == True) :
        print("Found a subset with given sum")
    else :
        print("No subset with given sum")

"""
4 - > 4,5,6,7
4,3,2,1
4 -> 1 , 2 ,3 ,4 

1           
4           
5           
1 4 5 3 2 
5-1=4
4-4 0
4- 5 =-1
4-3 = 1
1-2

money = 4
1 4 5 2 3
4 - 1 = 3
3 -2 = 1
1 2 3 4 5
4 - 1 = 3
3 - 2 = 1
4 - 3 = 1         

"""
