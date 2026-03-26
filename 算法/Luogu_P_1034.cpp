#include<bits/stdc++.h>
using namespace std;
int tmp[11], used[11], nums[]={0,0,1,1,1,2,2,2,3,3,3}, re=0, pos=0;
int len(int x){
    int s=-1, e;
    for(int i=0; i<11; i++){
        if(tmp[i]==x){
            if(s==-1)s=i;
            e=i;
        }
    }
    return e;
}
void dfs(){
    if(pos==11){
        if(len(1)==3 && len(2)==4 && len(3)==5){
            re++;
        }
    }
    for(int i=0; i<11; i++){
        if(used[i] || (i>0 && nums[i]==nums[i-1] && !used[i-1])){
            continue;
        }
        tmp[pos++]=nums[i];
        used[i]=true;
        dfs();
        used[i]=false;
        pos--;
    }
}
int main(){
    for(int i=0; i<11; i++){
        used[i]=false;
    }
    dfs();
    cout<<re;
}
/*
做题思路：
- 对多重集 {0,0,1,1,1,2,2,2,3,3,3} 做全排列计数（含去重）
- 使用 used[] 与“相同元素仅在前一个已使用时可用”的剪枝去重
- 每生成一个长度为 11 的排列，检查 1/2/3 的最后一次出现位置是否分别为 3/4/5
- 满足条件则计数加一；最后输出总数
- 注：源码中一处多余字符可能导致编译错误，需清理后编译
*/
