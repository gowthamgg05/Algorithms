#include<iostream>
#include<fstream>
#include<vector>	
#include<algorithm>	//*max_element()
using namespace std;

//Pass input file path as argument
int main(int argc,char **argv){
	int noOfValues,noofBins,temp,a[20]={0};
	vector<int> v;
	fstream fp(argv[1]);
	//Getting values from file
	if(fp){
		fp >> noOfValues >> noofBins;
		for(int i=0;i<noOfValues;i++){
			fp >> temp;
			v.push_back((int)temp);		
		}
	}
	else
	{
		cout << "Error in reading file";
	}
	//Range calculation
	int maximum = *max_element(v.begin(),v.end());
	int range = maximum/noofBins;
	
	//Constructing Histogram
	int low=0,high=range;
	for(int i=0;i<noofBins;i++){
		for(int j=0;j<noOfValues;j++){
			if(v[j]>=low && v[j]<=high){
				a[i]++;
			}
		}
		low=low+noofBins;
		high=high+noofBins;
	}
	
	//Display the Result
	low=0,high=range;
	for(int i=0;i<noofBins;i++){
		cout <<low << " - "<< high <<"\t"<<a[i] <<"\n";
		low=low+noofBins;
                high=high+noofBins;
	}
}
