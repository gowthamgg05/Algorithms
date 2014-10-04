nclude <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a[]={7,1,2,4,6,5,3};
    int x = a[4];
    int i = 0;
    for(int j=i+1;j<7;j++){
        if(a[j]<x){
            i+=1;
            int temp;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    for(int k=0;k<7;k++){
        cout << a[k] << endl;
    }
    cout << "pivot" << i;
    return a[i];
}

