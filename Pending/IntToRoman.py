# Compare given number with base values in the order 1000, 900, 500, 400, 100, 90, 50, 40, 
# 10, 9, 5, 4, 1. 
# Base value which is just smaller or equal to the given number will be the initial base value 
# (largest base value). 
# Divide the number by its largest base value, the corresponding base symbol will be repeated 
# quotient times, the remainder will then become the number for future division and repetitions.
# The process will be repeated until the number becomes zero.


def roman(n):
    l = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    d = {1:'I',4:'IV',5:'V',9:'IX', 10:'X',40:'XL',50:'L',90:'XC',100:'C',400:'CD',500:'D',900:'CM',1000:'M'}
    roman = ""
    num = n
    while num>0:    
        for elem in l:
            if num>=elem:
                qu = num//elem
                num = num%elem
                roman+=str(qu*d[elem])
    return roman
            


num = int(input("Enter num: "))
ans = roman(num)
print(ans)