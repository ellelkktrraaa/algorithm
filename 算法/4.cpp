#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> link_table(n,0);
    for(int i=1; i<n; i++){
        cin>>link_table[i];
    }

    int q;
    cin>>q;
    for(int j=0; j<q; j++){
        int m;
        cin>>m;
        unordered_map<int, set<int>> dirc;
        vector<int> stf_li(m, -1);
        for(int i=0; i<m; i++){
            cin>>stf_li[i];
            int cur = stf_li[i];
            dirc[stf_li[i]].insert(cur);
            while(link_table[cur]){
                cur = link_table[cur];
                dirc[stf_li[i]].insert(cur);
            }
            dirc[stf_li[i]].insert(0);
        }
        vector<int> res;
        res.reserve(m-1);
        for(auto i: dirc[stf_li[0]]){
            res.push_back(i);
        }
        for(int i=1; i<m; i++){
            vector<int> tmp;
            set_intersection(res.begin(),res.end(), dirc[stf_li[i]].begin(),dirc[stf_li[i]].end(), back_inserter(tmp));
            res=tmp;
        }
        cout<<res.back()<<endl;
    }
}