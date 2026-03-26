#include<bits/stdc++.h>
using namespace std;
long long n=1000, l=0;
string s="ABC";

long long dfs(long long l, long long n){
    if(n<=l){
        return n-1;
    }
    long long m=l;
    while(m*2<n){
        m*=2;
    }
    long long nw_n=(n-m-2)%m;
    if(nw_n<0){
        nw_n+=m;
    }
    nw_n+=1;
    return dfs(l, nw_n);
}

int main(){
    // cin>>s>>n;
    l=s.size();
    long long p=dfs(l, n);
    cout<<p<<endl;
    cout<<s[p];
}
/*
做题思路：
- 给定基串 s 与位置 n，按“长度成倍扩展并在中间插入字符”的构造查找第 n 个字符
- 通过寻找不超过 n 的最大块长 m（按 2 的幂扩展），把位置 n 归约到上一层区间
- 递归地将 n 映射回区间 [1,|s|]，最终返回 s[n-1]
- 只做索引映射，不显式构造大串，时间复杂度对数级
*/
