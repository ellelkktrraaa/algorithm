//P1044
#include<bits/stdc++.h>
using namespace std;
unsigned long long f[30][30];
unsigned long long times=0;
unsigned long long dfs(int mid, int right){
    if(f[mid][right]!=0){
        return f[mid][right];
    }
    if(right==0){
        f[mid][0]=1;
        return 1;
    }
    if(mid==0){
        for(int push = 1; push<=right; push++){
            times++;
            f[mid][right]+=dfs(push, right-push);
        }
    }else{
        for(int pop = 1; pop<=mid; pop++){
            for(int push = 1; push<=right; push++){
                times++;
                f[mid][right]+=dfs(mid-pop+push, right-push);
            }    
        }
    }
    return f[mid][right];
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            f[i][j]=0;
        }
    }
    dfs(0, n);
    cout<<f[0][n]<<endl;
    cout<<times<<endl;
    return 0;
}
/*
做题思路：
- 同样求栈合法序列数，但用状态记忆化
- f[mid][right] 表示当前栈内 mid、剩余可压栈 right 的方案数
- 当 right==0 时只有一种把剩余元素全部弹空的方式
- 否则枚举可弹出/可压入的数量并递归累计，利用 f 缓存避免重复计算
- 相较纯 DFS 减少重复子问题，但该枚举实现仍较耗时
*/
