#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> t;
vector<int> fa;
vector<vector<int>> link_table;
vector<int> indeg;
map<string, int> re;

int main(){

    int n;cin>>n;
    fa.resize(n, -1);
    link_table.resize(n);
    indeg.resize(n, 0);
    t.resize(n);

    for(int i=0; i<n; i++){
        t[i].resize(n);
        for(int j=0; j<n; j++){
            cin>>t[i][j];
        }
    }

    // re[string] 映射列表头字符到其在 t[0] 中的索引 (1..n-1)
    for(int j=1; j<n; j++) re[t[0][j]]=j;

    int zero_idx = -1;
    // 寻找代表 0 的行索引 i。若某行 i 满足 t[i][j] == t[0][j] (即 X+Y=Y)，则行首 t[i][0] 为 0。
    for(int i=1; i<n; i++){
        bool is_zero = true;
        for(int j=1; j<n; j++){
            if(t[i][j] != t[0][j]) { is_zero = false; break; }
        }
        if(is_zero) { zero_idx = i; break; }
    }

    if(zero_idx == -1) {cout<<"ERROR!"; return 0;}
    int zero_id = re[t[zero_idx][0]]; // 0 字符在列表头中的 ID

    // 2. 建立偏序关系图 (DAG)
    // 如果 X + Y = Z 且 Y != 0，则 X < Z。
    for(int i=1; i<n; i++){
        if(i == zero_idx) continue;
        int row_id = re[t[i][0]]; // 行首字符在列表头中的 ID
        for(int j=1; j<n; j++){
            if(re[t[0][j]] == zero_id) continue;
            // 结果只取一位的情况（无进位）
            if(t[i][j].size() == 1){
                int res_id = re[t[i][j]];
                if(res_id != row_id){ // 避免自环，建立偏序 row_id < res_id
                    bool exists = false;
                    for(int x : link_table[row_id]) if(x == res_id) exists = true;
                    if(!exists) {
                        link_table[row_id].push_back(res_id);
                        indeg[res_id]++;
                    }
                }
            }
        }
    }

    deque<int> q;
    vector<int> fina;
    // 0 字符的入度一定是 0
    q.push_back(zero_id);
    vector<bool> used_id(n, false);
    used_id[zero_id] = true;

    // 其他入度为 0 的非零字符
    for(int i=1; i<n; i++){
        if(i != zero_id && indeg[i] == 0) {
            q.push_back(i);
            used_id[i] = true;
        }
    }

    while(!q.empty()){
        if(q.size() > 1) { /* 允许分支，由最后验证逻辑把关 */ }
        int u = q.front(); q.pop_front();
        fina.push_back(u);
        for(int v : link_table[u]){
            if(--indeg[v] == 0){
                q.push_back(v);
                used_id[v] = true;
            }
        }
    }

    if(fina.size() < n-1) {cout<<"ERROR!"; return 0;}

    map<string, int> val;
    for (int i = 0; i < (int)fina.size(); i++) {
        val[t[0][fina[i+1]]] = i;
    }

    int base = n - 1; // 进制为 N-1
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int v1 = val[t[i][0]];
            int v2 = val[t[0][j]];
            string s = t[i][j];
            int actual;
            if (s.size() == 1) {
                if (val.find(s) == val.end()) { cout << "ERROR!"; return 0; }
                actual = val[s];
            } else {
                string s1 = "", s2 = "";
                s1 += s[0]; s2 += s[1];
                if (val.find(s1) == val.end() || val.find(s2) == val.end()) { cout << "ERROR!"; return 0; }
                actual = val[s1] * base + val[s2];
            }
            // 核心校验：加法表必须满足 v1 + v2 = actual
            if (v1 + v2 != actual) {
                cout << "ERROR!" << endl;
                return 0;
            }
        }
    }

    // 5. 格式化输出
    for (int i = 1; i < n; i++) {
        string char_name = t[0][i];
        cout << char_name << "=" << val[char_name] << (i == n - 1 ? "" : " ");
    }
    cout << endl << base << endl;

    return 0;
}
