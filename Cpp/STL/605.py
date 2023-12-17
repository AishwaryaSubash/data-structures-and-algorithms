def canPlaceFlowers(fb, n):
    if n==0:
        return True
    for i in range(len(fb)):
        if (fb[i]==0 and (i==0 or fb[i-1]==0) and (i==len(fb)-1 or fb[i+1]==0)):
            fb[i]=1
            n-=1
            if (n==0):
                return True
    return False

flowerbed = [1,0,0,0,1]
n = 1

print(canPlaceFlowers(flowerbed, n))