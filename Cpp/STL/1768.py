word1 = "abccccccccccccccc"
word2 = "pqrstuvw"

if len(word1)<len(word2):
    length = len(word1)
else:
    length = len(word2)

ans = ""
for i in range(length):
    ans+=word1[i] + word2[i]
    if i==length-1:
        if length!=len(word2):
            ans+=word2[i+1:]
        if length!=len(word1):
            ans+=word1[i+1:]

print(ans)