//P1464
#include<bits/stdc++.h>
using namespace std;
int wm[25][25][25];
int w(long long a, long long b, long long c){
    if(a<1 || b<1 || c<1)return 1;
    if(a>20 || b>20 || c>20)return w(20,20,20);
    if(wm[a][b][c]==0){
        if(a<b && b<c){
            wm[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
        }else{
            wm[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
        }
    }
    return wm[a][b][c];
}
int main(){
    for (int q=1;q<21;q++){
        for (int w=1;w<21;w++){
            for (int e=1;e<21;e++){
                wm[q][w][e]=0;
            }
        }
    }
    long long a, b, c;
    while(1){
        cin>>a>>b>>c;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<endl;
        if(a==-1 && b==-1 && c==-1){
            break;
        }
    }
    return 0;
}
/*
做题思路：
- 经典函数 w(a,b,c) 的记忆化搜索
- 边界：有一项 <1 返回 1；有一项 >20 统一折算为 w(20,20,20)
- 状态转移：
  - 若 a<b<c：w(a,b,c)=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c)
  - 否则：w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1)
- 用 3D 数组缓存 w[a][b][c]，避免指数级重复计算
*/
