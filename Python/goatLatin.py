def func(word, ind):
    if word[0] not in ['a','e','i','o','u']:
        word+=word[0]
        word = word[1:]
    word+='ma'
    word+='a'*(ind+1)
    return word

s = input()
l = s.split()
m = ""
for i in range(len(l)):
    w = func(l[i],i)
    m+=w
    m+=" "
print(m)
