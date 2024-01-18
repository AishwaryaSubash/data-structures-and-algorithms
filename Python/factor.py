l=[]  
def prime(n):
    for i in range(n//2,2,-1):
        if n%i==0:
            return False 
    else:
        l.append(n)
        return True            
    
def func(n):
    for i in range(n//2,2,-1):
        if n%i==0:
            print(i) 
            break                

for num in range(10,21):
    if prime(num)==False:
        func(num)
print(l)
