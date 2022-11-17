# 1) Start in the leftmost column
# 2) If all queens are placed
#     return true
# 3) Try all rows in the current column. 
#    Do following for every tried row.
#     a) If the queen can be placed safely in this row 
#        then mark this [row, column] as part of the 
#        solution and recursively check if placing
#        queen here leads to a solution.
#     b) If placing the queen in [row, column] leads to
#        a solution then return true.
#     c) If placing queen doesn't lead to a solution then
#        unmark this [row, column] (Backtrack) and go to 
#        step (a) to try other rows.
# 4) If all rows have been tried and nothing worked,
#    return false to trigger backtracking.


# 00 01 02 03
# 10 11 12 13
# 20 21 22 23
# 30 31 32 33


def safe(qno, qpos):
    i,j=0,0
    for key in qpos:
        if qno==1:
            if qpos[qno+1][i+1]-qpos[qno][i]!=1 and qpos[qno+1][j+1]-qpos[qno][j]!=1:
                i+=1
                j+=1
                continue
        if qno==len(qpos):
            if qpos[qno][i]-qpos[qno-1][i-1]!=1 and qpos[qno][j]-qpos[qno-1][j-1]!=1:
                i+=1
                j+=1
                continue
        if qpos[qno+1][i+1]-qpos[qno][i]!=1 and qpos[qno+1][j+1]-qpos[qno][j]!=1 and qpos[qno][i]-qpos[qno-1][i-1]!=1 and qpos[qno][j]-qpos[qno-1][j-1]!=1:
            i+=1
            j+=1
            continue
        else:
            return False
    return True

n = int(input("Enter r/c: "))


# qpos = {1:[0,0], 2:[1,0],3:[2,0], 4:[3,0]}
qpos = {}
for i in range(n):
    qpos[i+1] = []

qno=1
# col = [0,0,0,0]
for r in range(n):
    for c in range(n):
        if safe(qno, qpos):
            qpos[qno] = [r,c]
            # col[qno-1] = c
        else:
            break
    if qno==4:  #solution
        break
    qno+=1
    print(qpos)

print(qpos)
