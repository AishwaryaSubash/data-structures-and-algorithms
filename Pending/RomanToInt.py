# Algorithm to convert Roman Numerals to Integer Number:  

# Split the Roman Numeral string into Roman Symbols (character).
# Convert each symbol of Roman Numerals into the value it represents.
# Take symbol one by one from starting from index 0: 
#   If current value of symbol is greater than or equal to the value of next symbol, then add this value to the running total.
#   Else subtract this value by adding the value of next symbol to the running total.

def number(l):
    d = {'I':1,'V':5, 'X':10,'L':50,'C':100,'D':500,'M':1000}
    val = 0
    # rom = {}
    i=0
    while i<len(l):
    # for i in range(len(l)):
        if l[i] in d:
            if i==(len(l)-1):
                val+=d[l[i]]
            elif d[l[i]]>=d[l[i+1]]:
                val+=d[l[i]]
            else:
                val+=d[l[i+1]]
                val-=d[l[i]]
                i+=1
        else:
            return -1
        i+=1
    return val

s = input('Enter roman:')
l = list(s)
# print(l)
ans = number(l)
if ans==-1:
    print("Invalid num")
else:
    print("ans ",ans)