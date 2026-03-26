#include<bits/stdc++.h>
#define A_MAX 200
using namespace std;

string dfs(int n){
    if(n==0){return "0";}
    if(n==1){return "2(0)";}
    else if(n==2){return "2";}
    else{
        short a[A_MAX];
        string res="";
        int k=n, pos=0;
        for(int i=0; i<A_MAX; i++){
            a[i]=0;
        }
        while(k!=0){
            a[pos++]=k%2;
            k/=2;
        }
        const int p = pos-1;
        for(int i=p; i>=0; i--){
            if(a[i]==0)continue;
            else if(i>1){
                res+="2(";
                res+=dfs(i);
                res+=")+";
            }
            else{
                res+=dfs(i+1);
                res+="+";
            }
        }
        res.pop_back();
        return res;
    }
}
int main(){
    int n;
    cin>>n;
    cout<<dfs(n);
    return 0;
}
/*
做题思路：
- 将整数 n 按二进制拆为若干 2 的幂之和
- 对每个二进制位 i 为 1 的幂，用 “2(x)” 的形式递归表示指数 x；i∈{0,1,2} 设专门格式
- 由高位到低位拼接，中间用 ‘+’ 连接，得到幂次方表示
*/
