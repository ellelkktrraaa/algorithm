#pragma once
#include<bits/stdc++.h>
#include<ctime>
#include<chrono>
#include<cstdlib>
using namespace std;

vector<int> genRandArr(int n, int l, int r){
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        arr[i] = rand()%r+l;
    }
    return arr;
}

int omo(void func(vector<int>&), int n){
    srand(time(NULL));
    vector<int> arr = genRandArr(n, 0, 10000000), brr = arr;
    auto t = chrono::steady_clock::now();
    func(arr);
    cout<<"custom sort "<<chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now()-t).count()<<endl;
    auto t1 = chrono::steady_clock::now();
    sort(brr.begin(), brr.end());
    cout<<"std sort "<<chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now()-t1).count()<<endl;
    return 0;
}