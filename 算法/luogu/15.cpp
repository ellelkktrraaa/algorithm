//P1255
#include<bits/stdc++.h>
using namespace std;
long long re[5000] = {0};
int main(){
    re[1]=1;
    re[2]=2;
    int n;
    cin>>n;
    if(n<=0)return 0;
    const int lim = n;
    for(int i = 3; i <= lim; i++){
        re[i]=re[i-1]+re[i-2];
    }
    cout<<re[n];
    return 0;
}
/*
做题思路：
- 经典爬楼梯计数，等价于斐波那契：f1=1, f2=2，f[i]=f[i-1]+f[i-2]
- 自底向上迭代累加，时间 O(n)，空间 O(n)（可进一步压缩为 O(1)）
*/
