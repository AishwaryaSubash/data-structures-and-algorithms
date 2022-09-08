#import string
a = input()
b = input()
a = a.lower()
b = b.lower()
aele = {}
bele = {}
de = 0
count = 0
def count(s, d):
    for i in s:
        if i not in d:
            d[i] = 1
        else:
            d[i] += 1

count(a,aele)
count(b,bele)
print(aele,bele)
seta = set(aele.keys())
setb = set(bele.keys())
for i in seta:
    count+=aele[i] 
# abc = []
# for letter in string.ascii_lowercase:
#    abc.append(letter)




# a = a.lower()
# b = b.lower()
# a = [i for i in a]
# b = [i for i in b]
# print(a,b)
# a = sorted(a)
# b = sorted(b)
# print(a,b)
# c=0
# for iter in range(min(len(a), len(b))):
#     for i in a:
#         ac = a.count(i)
#     for j in b:
#         bc = b.count(j)
#     if ac==bc:
#         continue
#     else:
#         c+=abs(ac-bc)
# print(c)

