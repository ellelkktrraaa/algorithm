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

int getDigit(int num, int pos){
    for(int i=0;i<pos;i++)num/=10;
    return num%10;
}

void radixSort(vector<int>& arr, float lim){
    int j = 0;
    for(int i=0;i<arr.size();i++){
        j = max(j, arr[i]);
    }
    j = to_string(j).size();
    int n = j+1;
    while(--n>0){
        vector<vector<int>> buckets(10);
        for(int i=0;i<arr.size();i++){
            buckets[getDigit(arr[i], j-n)].push_back(arr[i]);
        }
        int n = 0;
        for(int i=0;i<buckets.size();i++){
            for(int j=0;j<buckets[i].size();j++){
                arr[n++]=(buckets[i][j]);
            }
        }
        if(n<=j*lim){
            int c=0;
            for(int i=0;i<n;i++){
                c++;
                if(arr[i]>arr[i+1])break;
            }
            if(c==n)break;
        }
    }
}
void RradixSort(vector<int>& arr){
    int j = 0;
    for(int i=0;i<arr.size();i++){
        j = max(j, arr[i]);
    }
    j = to_string(j).size();
    int n = j+1;
    while(--n>0){
        vector<vector<int>> buckets(10);
        for(int i=0;i<arr.size();i++){
            buckets[getDigit(arr[i], j-n)].push_back(arr[i]);
        }
        int n = 0;
        for(int i=0;i<buckets.size();i++){
            for(int j=0;j<buckets[i].size();j++){
                arr[n++]=(buckets[i][j]);
            }
        }
    }
}

int main(){
    float lim;
    int num;
    cin>>lim>>num;
    srand(time(NULL));
    vector<int> arr = genRandArr(num, 0, 10000000), brr = arr, crr = arr;

    auto t = chrono::steady_clock::now();
    radixSort(arr, lim);
    cout<<chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now()-t).count()<<endl;
    auto t1 = chrono::steady_clock::now();
    sort(brr.begin(), brr.end());
    cout<<chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now()-t1).count()<<endl;
    auto t2 = chrono::steady_clock::now();
    RradixSort(crr);
    cout<<chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now()-t2).count()<<endl;
    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i]<<" ";
    // }

    //result: the lim and num is irrelevant! the better way is no pre-check.
}