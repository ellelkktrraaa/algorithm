#include<bits/stdc++.h>
#include<ctime>
#include<chrono>
#include<cstdlib>
#include "heap.h"

using namespace std;
int main(){
    srand(time(NULL));
    vector<int> arr = genRandArr(1000000, 0, 10000000), brr = arr;
    auto t = chrono::steady_clock::now();
    heapSort(arr);
    cout<<chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now()-t).count()<<endl;
    auto t1 = chrono::steady_clock::now();
    sort(brr.begin(), brr.end());
    cout<<chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now()-t1).count()<<endl;
    return 0;
}