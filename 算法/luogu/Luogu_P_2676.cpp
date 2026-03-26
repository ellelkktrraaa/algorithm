#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll= long long;
int main(){
    ll n, h;
    vector<int>cow;
    cin>>n>>h;
    cow.resize(n);
    for(int i=0; i<n; i++){
        cin>>cow[i];
    }
    sort(cow.begin(), cow.end());
    int res=0;
    for(int i=n-1; i>=0; i--){
        if(h>0){
            h-=cow[i];
            res++;
        }
    }
    cout<<res;
}