def substrCount(n, s):
    count = 0
    for i in range(n):
        for j in range(i, n):
            str1 = s[i:j+1]
            if (len(str1) == 1):
                count += 1
            elif len(str1) % 2 == 0:
                if len(set(str1)) == 1:
                    count += 1
            else:
                mid = int(len(str1)/2)
                if str1[0:mid] == str1[mid+1:]:
                    count += 1
    print(count)


n = int(input())
s = input()
result = substrCount(n, s)
