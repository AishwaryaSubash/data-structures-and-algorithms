# aaaa => a,a,a,a,aa,aa,aa
def allSame(s):
    for i in range(1, len(s)):
        if s[0] != s[i]:
            return False
    return True

def oddSame(s):
    pass

def substrCount(n, s):
    count = 0
    l = []
    al = []
    for i in range(len(s)):
        for j in range(i, len(s)+1):
            if s[i:j] !='':
                # al.append(s[i:j])
                if len(s[i:j]) % 2 == 0:
                    if allSame(s[i:j]):
                        l.append(s[i:j])
                else:
                    print(s[i:j])
                    mid = round(len(s[i:j])/2)
                    print(mid)
        
    print(l)
    print(al)

n = int(input())
s = input()
result = substrCount(n, s)


#if len(s[j:]) % 2 == 0:
            #     if allSame(s[j:]):
            #         l.append(s[j:])
            #     break
            # else:
            #     pass