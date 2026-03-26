#include<bits/stdc++.h>
using namespace std;
int main(){
    int m, n;
    cin>>m>>n;
    int k=n-m+1;
    if(k==1 || k==2){
        cout<<1;
        return 0;
    }
    int t=k-2;
    short a[500], b[500], c[500];
    for(int i=0;i<500;i++){
        a[i]=0;
        b[i]=0;
        c[i]=0;
    }
    a[499]=1;
    b[499]=1;
    for(int i=0;i<t/3;i++){
        
        int carry=0;
        for(int i=499;i>=0;i--){
            c[i]=(b[i]+a[i]+carry)%10;
            carry=(b[i]+a[i]+carry)/10;
        }
        for(int i=499  ;i>=0;i--){
            a[i]=(c[i]+b[i]+carry)%10;
            carry=(c[i]+b[i]+carry)/10;
        }
        for(int i=499;i>=0;i--){
            b[i]=(c[i]+a[i]+carry)%10;
            carry=(c[i]+a[i]+carry)/10;
        }
    }
    
    if(t%3>=1){
        int carry=0;
        for(int i=499;i>=0;i--){
            c[i]=(b[i]+a[i]+carry)%10;
            carry=(b[i]+a[i]+carry)/10;
        }
    }
    if(t%3==2){
        int carry=0;
        for(int i=499;i>=0;i--){
            a[i]=(c[i]+b[i]+carry)%10;
            carry=(c[i]+b[i]+carry)/10;
        }
    }
    //output
    if(t%3==0){
        bool flag=false;
        for(int i=0;i<500;i++){
            if(b[i]!=0) flag=true;
            if(flag){
                cout<<b[i];
            }
        }
    }
    else if(t%3==1){
        bool flag=false;
        for(int i=0;i<500;i++){
            if(c[i]!=0) flag=true;
            if(flag){
                cout<<c[i];
            }
        }
    }
    else if(t%3==2){
        bool flag=false;
        for(int i=0;i<500;i++){
            if(a[i]!=0) flag=true;
            if(flag){
                cout<<a[i];
            }
        }
    }
    return 0;
}
/*
做题思路：
- 计算斐波那契数 F_k（k=n-m+1），F1=F2=1，答案可能很大
- 使用长度 500 的数组按位存储十进制大整数，进行高精加法
- 以 3 次为一组滚动更新 c=b+a，a=c+b，b=c+a，加速循环
- 根据 t%3 选择当前对应的项输出，保证得到第 k 项
*/
