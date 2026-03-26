//P1044
#include<bits/stdc++.h>
using namespace std;
long long re = 0;
unsigned long long call_cnt = 0; // 统计递归调用次数

void dfs(int mid, int right) {
    call_cnt++; // 每次调用计数+1
    if (mid == 0 && right == 0) {
        re++;
        return;
    }
    if (mid > 0) dfs(mid - 1, right);
    if (right > 0) dfs(mid + 1, right - 1);
}

int main() {
    int n;
    cin >> n;
    dfs(0, n);
    cout << "times" << call_cnt << endl; // 输出：18
    cout << "res" << re << endl;       // 输出：5
    return 0;
}
/*
做题思路：
- 统计合法入栈/出栈序列的数量（卡特兰数）
- 参数 mid 表示当前栈内元素个数，right 表示剩余可入栈次数
- 当 mid>0 可执行一次出栈；当 right>0 可入栈；mid==0 且 right==0 计数加一
- 纯 DFS 穷举，时间指数级；用于直观验证卡特兰递推
*/
