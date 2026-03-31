#include<bits/stdc++.h>
using namespace std;
//big root heap
void dtu(vector<int> &arr){
    int n = -1, s = arr.size();
    while(n<s-1){
        n++;
        int m=n;
        int p=(m-1)/2;
        while(m>0 && arr[m]>arr[p]){
            swap(arr[m],arr[p]);
            m=p;
            p=(m-1)/2;
        }
    }
    return;
}
void utd(vector<int> &arr, int n){
    int s = arr.size();
    swap(arr[0],arr[s-n-1]);
    int p1 = 1, p2 = 2, m = 0;
    while(s-n-1>p2 && (arr[m]<arr[p1] || arr[m]<arr[p2])){
        int pos = arr[p1]>arr[p2]?p1:p2;
        swap(arr[m],arr[pos]);
        m=pos;
        p1 = m*2+1, p2 = m*2+2; 
    }
}

int main(){
    vector<int> arr = {11,2,3,43,5,6,3,3,2,43,4,3};
    dtu(arr);
    int n = -1;
    while(n<int(arr.size())-1){
        n++;
        utd(arr, n);
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}