#P1255
re=[0]*5001
n=int(input())
re[1]=1;re[2]=2
for i in range(3,n+1):
    re[i]=re[i-1]+re[i-2]
print(re[n])