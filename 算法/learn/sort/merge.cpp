#include<bits/stdc++.h>
#include "comp.h"
using namespace std;

void merge(const vector<int>&arr, vector<int>&tmp, int l, int r, int mid){
    //mid is in the right part
    int p = l, mi = mid;
    while(l<mi&&mid<=r){
        if(arr[l]<=arr[mid]){
            tmp[p]=arr[l];
            l++;
        }else{
            tmp[p]=arr[mid];
            mid++;
        }
        p++;
    }
    if(l<mi){
        for(int i = l; i<mi; i++){
            tmp[p] = arr[i];
            p++;
        }
    }else{
        for(int i = mid; i<=r; i++){
            tmp[p] = arr[i];
            p++;
        }
    }
}

void mergeSort(vector<int>&arr){
    int s = arr.size();
    vector<int> tmp = arr; 
    int group_size = 1;
    while(group_size<s){
        int l = 0, mid = group_size;
        int r = min(2*group_size-1, s-1);
        while(mid<s){
            merge(arr, tmp, l, r, mid);
            l = r+1; 
            mid = l+group_size;
            r = min(mid+group_size-1, s-1);
        }
        group_size*=2;
        arr = tmp;
    }
}

int main(){
    // vector<int> arr = {1, 5, 9, 12, 3, 6, 18};
    // mergeSort(arr);
    // for(int i = arr.size()-1; i>=0; i--){
    //     cout<<arr[i]<<endl;
    // }
    omo(mergeSort, 1000000);
    // vector<int> arr = {1, 5, 9, 12, 3, 6, 18}, tmp = arr;
    // merge(arr, tmp, 0, s-1, 4);
    // for(int i = s-1; i>=0; i--){
    //     cout<<tmp[i]<<endl;
    // }
}
      
