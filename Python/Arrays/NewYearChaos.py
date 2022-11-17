def minimumBribes(l):
    count = 0
    flag =0
    #cpy = [0 for i in range(len(l))]
    
    for i in range(len(l)-1):
        if l[i]-l[(i+1)]>2:
            print("Too chaotic")
            flag = 1
            break
        elif l[i]>l[i+1]:
            temp= l[i]
            l[i] = l[i+1]
            l[i+1] = temp
            count+=1
    if flag==0:
        print(count)

t = int(input().strip())

for t_itr in range(t):
    n = int(input().strip())
    q = list(map(int, input().rstrip().split()))
    minimumBribes(q)

"""
8 1 6 4 3

1 2 4 5 3
1 2 4 3 5
1 2 3 4 5
 for (int i = q.size() - 1; i >= 0; i--) {
        if (q[i] - (i + 1) > 2) {
            cout << "Too chaotic" << endl;
            return;}
4 1 2 3
1 4 2 3
1 2 4 3

2 1 5 3

1 2 5 3
1 2 3 5

"""
