#include<iostream>
using namespace std;
using ull=unsigned long long;
int main(){
    ull n=20240601LL, cur=1;
    for(int i=1; i<n; i++){
        cur+=(i*5+1);
    }
    cout<<cur;
}