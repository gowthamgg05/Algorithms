#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void display(vector<int> v){
	for(int i=0;i<v.size();i++){
		cout << v[i] << "\t";
	}
}
//Comparing function for sort
bool desc(int i, int j) { return i > j; }

//Function that takes an element and decides where to put based on space availability in the bin
void binPack(vector<int> v,int binSize,int binSpace,vector<int> bins,int nbins){
        for(int i=0;i<v.size();i++){
                if(v[i]<=binSize){
			//Check for binspace
                        if(v[i]<=binSpace){
                                if(i==0){
                                        bins.push_back(v[i]);
                                }else
                                {
                                        //Update the bin value
					bins[nbins] += v[i];
                                }
				//Decrease the binspace that an element takes
                                binSpace -= v[i];
                        }else{
				//Create a new bin
                                bins.push_back(v[i]);
                                binSpace = binSize - v[i];
				//Update no.of bins                      
                                nbins++;
                        }
                }else{
                        cout << "Element greater than binSize";
                        break;
                }       
        }
        display(bins);
        cout << endl << "No.of Bins " << (nbins+1);
}
int main(){
	int arr[] = {3,4,5,6,7,8,1,2,3,4,5,6,7,8,9};
	vector<int> v(arr, arr + sizeof arr / sizeof arr[0]);
	cout << "Elements" << endl;
	display(v);	
	//Bin size
	int binSize = 10;
	int nbins=0;
	int binSpace = binSize;
	vector<int> bins;
	cout << endl << "Best Fit" << endl;
	//Sorting elements descending for best fit
	sort(v.begin(),v.end(),desc);
	binPack(v,binSize,binSpace,bins,nbins);
	cout << endl << "Worst Fit" << endl;
	//Sorting elements ascending for worst fit
	sort(v.begin(),v.end());
	binPack(v,binSize,binSpace,bins,nbins);
	return 0;
}
