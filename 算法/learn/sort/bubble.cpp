#include<bits/stdc++.h>
#include "comp.h"
using namespace std;

void bubbleSort(vector<int>& arr){
    int s = arr.size();
    for(int i=0; i<s; i++){
        for(int j=0; j<s-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    omo(bubbleSort, 10000);
}