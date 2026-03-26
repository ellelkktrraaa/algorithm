//P1928
#include<bits/stdc++.h>
using namespace std;

string in = "", re = "";
int p = 0;

string dfs(){
    string tmp = "";
    unsigned short num = 0;
    while(p<in.size()){
        if(in[p]>='A'&& in[p]<='Z'){
            tmp+=in[p];
            p++;
        }
        else if(in[p] == '['){
            p++;
            while(in[p]>='0' && in[p]<='9'){
                num = num*10 + (in[p]-'0');
                p++;
            }//p at first non-digit
            string dr = dfs();
            for(int i=0;i<num;i++){
                tmp+=dr;
            }
            num=0;
        }
        else if(in[p] == ']'){
            p++;
            if(num==0){
                return tmp;
            }
            string res = "";
            for(int i=0;i<num;i++){
                res+=tmp;
            }
            return res;
        }
    }
    return tmp;
}
int main(){
    cin>>in;
    re+=dfs();
    cout<<re;
    return 0;
}
/*
做题思路：
- 递归下降解析形如 “K[...]+嵌套” 的字符串展开
- 指针 p 线性扫描：
  - 遇到大写字母直接拼接
  - 遇到 '[' 先读取其前面的数字倍数，递归解析子串，返回后按倍数重复拼接
  - 遇到 ']' 返回当前层结果
- 支持多层嵌套，时间复杂度与展开后长度近似线性
*/
