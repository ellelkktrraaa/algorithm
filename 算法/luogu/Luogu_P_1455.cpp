#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct UnionFind{
    vector<int> fa, hg;
    UnionFind(int n){
        fa.resize(n), hg.resize(n);
        iota(fa.begin(), fa.end(), 0);
        fill(hg.begin(), hg.end(), 1);
    }
    int find(int x){
        fa[x] = (fa[x] == x ? x : find(fa[x]));
        return fa[x];
    }
    void union(int x, int y){
        int fx = find(x), fy = find(y);
        if(fx == fy)return;
        if(hg[fx]<hg[fy])fa[fx] = fy;
        else{
            fa[fy] = fx;
            if(hg[fx] == hg[fy])hg[fx]++;
        }
    }
    bool joint(int x, int y){
        return find(x) == find(y);
    }
}

int main(){
    int n, m, w;
    cin>>n>>m>>w;
    vector<int> p, v;
    UnionFind uf(n+1);

    p.reserve(n); v.reserve(n);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        p.push_back(x);
        cin>>x;
        v.push_back(x);
    }
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        uf.union(x, y);
    }
    //
}
