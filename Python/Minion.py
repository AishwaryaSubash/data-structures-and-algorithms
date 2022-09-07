# comb = []
# d=set()
# count=0
# kevin=0
# stu=0
# def findSubstring(s):
#     for i in range(len(s)+1):
#         for j in range(i):
#             comb.append(s[j:i])

# def isVowel(x):
#     if (x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u'):
#         return True
#     else:
#         return False

# def calc(comb):
#     global count,kevin,stu
#     for elem in comb:
#         d.add((elem, comb.count(elem)))
#         if isVowel(elem[0]):
#             kevin = kevin + 1
#         else:
#             stu = stu + 1


# s = input("Enter string: ")
# s = s.lower()
# # print(s)
# findSubstring(s)
# print(comb)
# calc(comb)
# print(kevin, stu)


def minion_game(s):
    comb = {}
    
    def findSubstring(s):
        for i in range(len(s)+1):
            for j in range(i):
                if s[j:i] in comb:
                    comb[s[j:i]] += 1
                else:
                    comb[s[j:i]] = 1

    def calc(comb):
        kevin = 0
        stu = 0
        for elem in comb.keys():
            if elem[0] in "aeoiu":
                kevin += comb[elem]
            else:
                stu += comb[elem]
        if kevin > stu:
            print("Kevin", kevin)
        elif stu > kevin:
            print("Stuart", stu)
        else:
            print("Draw")

    s = s.lower()
    findSubstring(s)

    calc(comb)


if __name__ == '__main__':
    s = input()
    minion_game(s)
