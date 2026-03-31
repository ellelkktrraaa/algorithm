import random
x=random.randint(0,101)
i=102
n=0
while i!=x:
    n+=1
    try:
        i=int(input("plz input num(0,100)"))
    except Exception:
        continue

    if i>x: 
        print("less than", i)
    elif i<x:
        print("lager than", i)
print("you win in", n, "step")
    