#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k=1;
    while(k*(k+1)/2<n){
        k++;
    }
    int m=n-k*(k-1)/2;
    cout<<k<<endl;
    if(k&1){cout<<k-m+1<<"/"<<m;}
    else{cout<<m<<"/"<<k-m+1;}
}