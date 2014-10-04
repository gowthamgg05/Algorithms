#include<iostream>
#include <vector>
#include<fstream>
using namespace std;

//No.of pairs that has the difference k 
int pairs(vector <int> &a,int k) {
	int ans=0;
   	for(int i=0;i<a.size();i++){
       		for(int j=i+1;j<a.size();j++){
           		if(a[i]-a[j]==k || a[j]-a[i]==k){
               			ans+=1;
           		}
       		}
   	} 
	return ans;
}

int main(int argc,char **argv) {
	int result;    
    	int n,k;
	ifstream fp(argv[1]);
    	if(fp){
		fp >> n >> k; 
    		vector<int> a;
    		int item;
    		for(int i=0;i<n;i++){
        		fp >> item;
        		a.push_back(item);
    		}

    		result = pairs(a,k);
    		cout << result;
	}
	else
	{
		cout << "File not found";
	}    
    	return 0;
}

