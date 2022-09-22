def isBalanced(s):
    if len(s)%2==0:
        stk = []
        flag = 0
        for i in range(len(s)):
            if s[i] in ['{', '[', '(']:
                stk.append(s[i])
            else:
                if len(stk) == 0:
                    return "NO"
                if s[i]=='}':
                    if stk[len(stk)-1]=='{':
                        stk.pop()
                    else:
                        flag = 1
                elif s[i]==')':
                    if stk[len(stk)-1]=='(':
                        stk.pop()
                    else:
                        flag = 1
                elif s[i]==']':
                    if stk[len(stk)-1]=='[':
                        stk.pop()
                    else:
                        flag = 1
        if flag == 1:
            flag = 0
            return "NO"
        if len(stk)==0:
            return "YES"
        else:
            return "NO"
    else:
        return "NO"
            
    

l = []
n = int(input().strip())
for i in range(n):
    s = input()
    result = isBalanced(s)
    l.append(result)

for i in range(n):
    print(l[i])
