#pragma once
#include "gaosi.h"

int main(){
    Matrix m(2,3);
    m.set(0,0,1);
    m.set(0,1,1);
    m.set(0,2,1);
    m.set(1,0,2);
    m.set(1,1,1);
    m.set(1,2,1);

    m.print();
    vector<float>res=m.solve();

    int i=0;
    for(auto it: res){
        cout<<char(i+'a')<<": "<<it<<endl;
        i++;
    }
    
}