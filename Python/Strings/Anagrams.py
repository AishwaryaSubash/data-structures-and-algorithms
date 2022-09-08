#completed
a = input()
b = input()
a = a.lower()
b = b.lower()
aele = {}
bele = {}
de = 0
counter = 0


def count(s, d):
    for i in s:
        if i not in d:
            d[i] = 1
        else:
            d[i] += 1


count(a, aele)
count(b, bele)



def check(d, set):
    global counter
    for i in set:
        if i in d:
            counter += d[i]


seta = set(aele.keys())
setb = set(bele.keys())

check(aele, seta-setb)
check(bele, setb-seta)
inter = seta.intersection(setb)
for i in inter:
    counter += abs(aele[i]-bele[i])
print(counter)
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
