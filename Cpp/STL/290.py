# 290. Word Pattern

pattern = "abba"
s = "dog dog dog dog"
s = s.split(' ')
d = {}

if (len(set(pattern)) != len(set(s))):
    print(False)    # return
if (len(pattern) != len(s)):
    print(False)    # return
for i in range(len(pattern)):
    if pattern[i] not in d:
        d[pattern[i]] = s[i]
    elif d[pattern[i]] == s[i]:
        continue
    else:
        print(False)    #return
print(True)     #return

# My answer - using two dict

# pattern = "abba"
# s = "dog dog dog dog"
# arr = s.split(' ')
# ans = {}
# flag=0
# if len(pattern) != len(arr):
#     flag=1
# else:
#     for i in range(len(pattern)):
#         if pattern[i] in ans.keys():
#             if ans[pattern[i]] != arr[i]:
#                 flag=1
#                 break
#         else:
#             ans[pattern[i]] = arr[i]
# dup = {}
# for key, val in ans.items():
#     if val not in dup:
#         dup[val]=key
#     else:
#         flag=1
#         break
# if (flag==1):
#     print(False)
# else:
#     print(True)
    
