def checkMagazine(magazine, note,m,n):
    md ={}
    nd={}
    for i in magazine:
        if i not in md:
            md[i] = 1
        else:
            md[i] +=1
    for i in note:
        if i not in nd:
            nd[i] = 1
        else:
            nd[i] +=1
    flag = 0
    for key,val in md.items():
        if key in nd:
            if val - nd[key] !=0:
                flag = 1
        
    if flag == 0:
        for key,val in nd.items():
            if key not in md:
                flag = 1
        if flag==0:
            print("Yes")
        else:
            print("No")
    else:
        print("No")


inputs = input().rstrip().split()
m = int(inputs[0])
n = int(inputs[1])
magazine = input().rstrip().split()
note = input().rstrip().split()
print(m,n,magazine,note)
checkMagazine(magazine, note,m,n)
