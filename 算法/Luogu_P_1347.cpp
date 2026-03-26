//P1347
#include<bits/stdc++.h>
using namespace std;
string sqc;
vector<vector<int>> link_table;
vector<int>in_deg;
vector<int>re;
//0->weiwancheng; 1->wancheng; -1->maodun;

bool checkLoop(int n, vector<int>in_deg){
    //nodes存储可用的元素
    vector<bool> nodes(n, true);
    deque<int> q;

    for(int i=0; i<n; i++){
        if(in_deg[i]==0 && nodes[i])q.push_back(i);
        if(in_deg[i]==-1)nodes[i]=false;
    }

    if(q.empty())return true;

    while(!q.empty()){
        int cur = q.front();
        q.pop_front();
        nodes[cur]=false;
        for(auto it: link_table[cur]){
            in_deg[it]--;
            if(in_deg[it]==0){
                q.push_back(it);
            }
        }
    }

    //检查是否还有可用元素, 有就有环
    for(int i=0; i<n; i++){
        if(nodes[i])return true;
    }
    return false;
}

short checkOrder(int n){
    if(checkLoop(n, in_deg)){
        return -1;
    }
    //no_loop
    int n_0 = 0, n_n1 = 0;
    for(int i=0; i<n; i++){
        if(in_deg[i]==0){
            n_0++;
        }else if(in_deg[i]==-1){
            n_n1++;
        }
        if(n_0>1 || n_n1>0){
            return 0;
        }
    }
    int q;
    vector<int> tmp;
    //找到入度为0的点作为起点
    for(int i=0; i<n; i++)if(in_deg[i]==0)q=i;
    tmp.push_back(q);
    while(!link_table[q].empty()){
        q=link_table[q][0];
        tmp.push_back(q);
    }
    //检查是否所有元素都被访问到
    if(tmp.size()!=n){
        return 0;
    }
    re=tmp;
    return 1;
}

void sqcPros(){
    int idx = sqc[0] - 'A';
    int to = sqc[2] - 'A';
    if(count(link_table[idx].begin(), link_table[idx].end(), to))return;
    if(in_deg[to]==-1){in_deg[to]=1;}
    else{in_deg[to]++;}
    if(in_deg[idx]==-1)in_deg[idx]=0;
    link_table[idx].push_back(to);
}

int main(){
    int n,m;
    cin>>n>>m;
    in_deg.reserve(n);
    link_table.resize(n);
    for(int i=0; i<n; i++){
        in_deg.push_back(-1);
    }
    for(int i=0; i<m; i++){
        cin>>sqc;
        sqcPros();
        string output="";
        switch(checkOrder(n)){
            case 1:
                for(auto it: re)output+=char(it+'A');
                cout<<"Sorted sequence determined after "<<i+1<<" relations: "<<output<<".";
                return 0;
            case -1:
                cout<<"Inconsistency found after "<<i+1<<" relations.";
                return 0;
            case 0:
                break;
        }
    }
    cout<<"Sorted sequence cannot be determined.";
    return 0;
}