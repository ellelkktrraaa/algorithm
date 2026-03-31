#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, n, m, x, f[25]={0,1,1,2,3}, cnt[25]={0,1,1,2,2}, cx[25]={0,0,0,0,1,2,4,7};
    cin>>a>>n>>m>>x;
    for(int i=5; i<=n; i++){
        f[i]=f[i-1]+f[i-2];
        cnt[i]=cnt[i-1]+f[i-4];
        cx[i+2]=cx[i+1]+f[i-1];
    }
    int d=(m-a*cnt[n-1])/cx[n-1];
    cout<<a*(cnt[x])+d*cx[x];
}