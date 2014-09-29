#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int main(int argc,char **argv) 
{
	long long n, k;
    	vector<int> prices;
	fstream fp(argv[1]);
	if(fp)
	{
    		fp >> n >> k;
		int price;
		for(int i = 0; i < n; i++)
    		{
        		fp >> price;
			prices.push_back(price);
    		}
    		sort(prices.begin(), prices.end());
    		int answer = 0;
    		// Computing No.of Toys that can be bought using n,k,prices
    		int currentCost=0;
    		for(int i=0;i<n;i++){
			currentCost+=prices[i];
			if(currentCost<=k){
				answer++;
				cout << "Toy price : " << prices[i] << endl;
			}
    		}
		cout << "Total No.of Toys : ";
		cout << answer << endl;
    	}
	else
		cout << "Please mention the file path correctly";
}
