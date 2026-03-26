#include<bits/stdc++.h>
using namespace std;
int const MaxX = 1000, MaxY = 1000;
int main(){
    int a[MaxX][MaxY];
    int n;
    for(int i=0; i<MaxX; i++){
        for(int j=0; j<MaxY; j++){
            a[i][j] = -1;
        }
    }

    cin>>n;
    for(int i=0; i<n; i++){
        int left, down, xl, yl;
        cin>>left>>down>>xl>>yl;
        int right = left + xl, up = down + yl;
        for(int x=left; x<right; x++){
            for(int y=down; y<up; y++){
                a[x][y] = i+1;
            }
        }
    }
    int xq, yq;
    cin>>xq>>yq;
    cout<<a[xq][yq]<<endl;

}