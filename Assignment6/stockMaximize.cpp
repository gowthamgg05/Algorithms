#include <vector>
#include <iostream>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T,i,n,s;
    long max,profit;
    cin >> T;
    while(T--){
        vector<int> stockPrice;
        cin >> n;
        for(i=0;i<n;i++){
            cin >> s;
            stockPrice.push_back(s);
        }
        max = 0,profit=0;
        for(i=n-1;i>=0;i--){
            //cout << stockPrice[i] << "\t" << max << "\n";
            if(stockPrice[i] > max){
                max = stockPrice[i];
            }
            profit += (max - stockPrice[i]);
        }
        cout << profit << "\n";
    }
    //cout << T;
    return 0;
}
