#include <vector>	
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc,char **argv) {
    	int N,M,low,high,noOfCandies;
	fstream fp(argv[1]);
	if(fp){
		fp >> N >> M;	//No.of jars and no of operations
		vector<int> v(N,0);	
		for(int i=0;i<M;i++){
        	fp >> low >> high >> noOfCandies;	//indices and no.of candies
                	while(low<=high){
                		v[low-1]=v[low-1]+noOfCandies;
                		low++;
                	}
        	}
		int totalNoOfCandies=0;
        	for(int i=0;i<N;i++)
                	totalNoOfCandies+=v[i];	//averaging
        	cout << "Average Number of Candies: "; 
		cout << totalNoOfCandies/N;
	}
	else
	{
		cout << "File path not found";
	}
}
