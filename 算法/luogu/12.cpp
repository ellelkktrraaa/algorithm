//P1036
#include<bits/stdc++.h>
using namespace std;

int pr[700], pos=0,a[32];
bool is_p[10000];
void gp(){
    for(int i = 2; i<10000; i++){
        if(is_p[i]){
            pr[pos++]=i;
            for(int j = 2; j<10000/i; j++){
                is_p[j*i]=false;
            }
        }
    }
}

short chep(long long sum){
    if(sum==2)return 1;
    const int po = pos;
    for(int i=0; i < po; i++){
        int p=pr[i];
        if(sum % p == 0) return 0;
        if((unsigned long long)p * p > sum) return 1;
    }
    return 1;
}

long long sum=0, re=0;
void dfs(int l, int s, int k){
    if(k==0){
        re += chep(sum);
    }
    if(k>0){
        int m = l-k;
        for(int i=s; i<=m; i++){
            sum+=a[i];
            dfs(l,i+1,k-1);
            sum-=a[i];
        }
    }
}

int main(){
    for(int i = 0; i < 10000; i++){
        is_p[i] = true;
    }
    gp();
    int n,k;
    cin>>n>>k;
    for(int i = 0; i < 32; i++){
        a[i] = 0;
    }
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    dfs(n,0,k);
    cout<<re;
}
/*
做题思路：
- 在 n 个数中选出 k 个，使其和为质数的方案数
- DFS 组合枚举，使用回溯累加当前和，选满 k 个后进行质数判定
- 质数判定采用试除：预先生成若干小质数，判断到 p*p>sum 即可
- 结果累计到 re 输出
*/
