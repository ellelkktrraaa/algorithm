#include<bits/stdc++.h>
using namespace std;
int n=0, m[150]={0}, k;

void add(int mr[150], int m[150]){
    int re[150]={0}, carry=0;
    for(int i=0; i<k+1; i++){
        int tmp=mr[i]+m[i]+carry;
        re[i]+=tmp%n;
        carry=tmp/n;
    }
    if(re[k])k++;
    for(int i=0; i<k; i++)m[i]=re[i];
}

int main(){
    cin>>n;
    string s;
    cin>>s;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i]>='0'&&s[i]<='9')m[i]=s[i]-'0';
        else m[i]=s[i]-'A'+10;
    };
    k=s.size();
    int t=0, mr[150]={0};
    while(t<31){
        t++;
        memset(mr, 0, sizeof(mr));
        for(int i=0; i<k; i++){
            mr[i]=m[k-i-1];
        }
        add(mr, m);

        int l=0, r=k-1, flag=1;
        while(l<r){
            if(m[l]==m[r]){l++; r--; continue;}
            l++; r--;
            flag=0;
            break;
        }
        if(flag){
            cout<<"STEP="<<t<<endl;
            return 0;
        }
    }
    return 0;
}