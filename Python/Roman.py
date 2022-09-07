# order={'I':[ 'V', 'X'],'X':['L','C'],'C':['D','M']}

# I V X L C D M
# ret=True prec holds
#   ret=False wrong roman num


# I can be placed before V (5) and X (10) to make 4 and 9. 
# X can be placed before L (50) and C (100) to make 40 and 90. 
# C can be placed before D (500) and M (1000) to make 400 and 900.
#I<-V X L C
def prec(ind, c) :
    # print(c,s[ind+1])

    if (c =='I'):
        return s[ind+1]!='L' and s[ind+1]!='C' and s[ind+1]!='D' and s[ind+1]!='M'
    elif (c=='V'):
        return s[ind+1]!='V' and s[ind+1]!='X' and s[ind+1]!='L' and s[ind+1]!='C' and s[ind+1]!='D' and s[ind+1]!='M'
    elif (c =='X'):
        return s[ind+1]!='D' and s[ind+1]!='M'
    elif (c=="L"):
        return s[ind+1]!='L' and s[ind+1]!='C' and s[ind+1]!='D' and s[ind+1]!='M'
    elif (c=="D"):
        return s[ind+1]!='D' and s[ind+1]!='M'
    else:
        return True
            
s = input('Enter roman:')
string = list(enumerate(s,0))
for ind,elem in string:
    #print(i,j)
    if ind != (len(string)-1 ):
        retval = prec(ind,elem)
        if retval == False:
            print('Invalid roman num')
            break
else:
 
    print('Valid roman num')

    #sum
    order={'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500 ,'M':1000}
    sum=0
    for elem in range(0, len(s)):
        if sum>order[s[elem]]:
            sum=order[s[elem]]+sum
            print(sum)
        else:
            sum=order[s[elem]]-sum
            print(sum)
    print(sum)