import random
inlist = input("plz input func (1-4)").strip().lower().split()
li={"isfj":["si","fe","ti","ne"],
    "esfj":["fe","si","ne","ti"],
    "istj":["si","te","fi","ne"],
    "estj":["te","si","ne","fi"],
    "infp":["fi","ne","si","te"],
    "enfp":["ne","fi","te","si"],
    "infj":["ni","fe","ti","se"],
    "enfj":["fe","ni","se","ti"],
    "intp":["ti","ne","si","fe"],
    "entp":["ne","ti","fe","si"],
    "intj":["ni","te","fi","se"],
    "entj":["te","ni","se","fi"],
    "isfp":["fi","se","ni","te"],
    "esfp":["se","fi","te","ni"],
    "istp":["ti","se","ni","fe"],
    "estp":["se","ti","fe","ni"],
}
reli=[]
for it in li:
    p=0
    s=0
    for i in inlist:
        if i=="x":
            p+=1
            continue
        flag=0
        for j in range(0,4):
            if i == li[it][j]:
                s+=(5-p)**(2/3)*(abs(p-j))
                flag=1
                break
        if flag==0:
            s+=5+random.random()
        p+=1
    reli.append(s)
i=0
tb={}
for it in li:
    tb[reli[i]]=it
    i+=1

reli.sort()
reli.reverse()
for i in reli:
    print(tb[i],i)