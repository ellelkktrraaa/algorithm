//P1002
#include<bits/stdc++.h>
using namespace std;

int bx, by, kx, ky;
long long memo[30][30];
int unreachable[9][2];
unsigned long long dp(int x, int y) {
    for(int i = 0; i < 9; i++){
        if(x == unreachable[i][0] && y == unreachable[i][1]){
            memo[x][y]=0;
            break;
        }
    }
    if(memo[x][y] == -1){
        if(x!=0 && y!=0){
            memo[x][y]=dp(x-1,y)+dp(x,y-1);
        }
        else if(x == 0 && y != 0){
            memo[x][y]=dp(x,y-1);
        }
        else if(x != 0 && y == 0){
            memo[x][y]=dp(x-1,y);
        }
        else{
            memo[x][y]=1;
        }
    }
    return memo[x][y];
}
int main(){
    cin >> bx >> by >> kx >> ky;
    for(int i=0; i<=bx; i++){
        for(int j=0; j<=by; j++){
            memo[i][j]=-1;
        }
    }
    int temp[9][2] = {
        {kx, ky}, 
        {kx+2, ky+1}, 
        {kx+1, ky+2}, 
        {kx-1, ky+2}, 
        {kx-2, ky+1}, 
        {kx-2, ky-1}, 
        {kx-1, ky-2}, 
        {kx+1, ky-2},
        {kx+2, ky-1}
    };
    
    for(int i = 0; i < 9; i++) {
        unreachable[i][0] = temp[i][0];
        unreachable[i][1] = temp[i][1];
    }

    cout << dp(bx, by);
    
    return 0;
}
/*
做题思路：
- 计数从 (0,0) 到 (bx,by) 只向右/上走的路径数
- 将马 (kx,ky) 及其 8 个马步控制的格子标为不可达
- 递归 + 记忆化：dp(x,y)=dp(x-1,y)+dp(x,y-1)，遇到不可达格子为 0，dp(0,0)=1
- 自顶向下填表，最终输出 dp(bx,by)
*/
