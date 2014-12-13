#include<iostream>
#include<vector>
using namespace std;

// Function that constructs the the datastructure and maintains it using O(n^2) space
void constructDS(vector<int> &v,vector< vector<int> > &arr){
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.size();j++){
			if(j-i==0){
				arr[i][j]=v[i];
			}
			else if(j-i>0){
				if(arr[i][j-1]>=v[j])
					arr[i][j]=v[j];
				else
					arr[i][j]=arr[i][j-1];
			}
			else
				arr[i][j]=-1;
		}
	}
}
int main(){
	int arr[] = {5,2,3,1,7,8,9,12,3,45,78,96,44,34},i,j;
        vector<int> v(arr, arr + sizeof arr / sizeof arr[0]);
	vector< vector<int> > ds(v.size(), vector<int>(v.size()));
	cout << "Elements" << endl;
	for(int i=0;i<v.size();i++){
		cout << v[i] << "\t";
	}
	cout << endl << "Index" << endl;
        for(int i=0;i<v.size();i++){
                cout << i << "\t";
        }
	constructDS(v,ds);
	cout << endl << "Enter start index...";
	cin >> i;
	cout << "Enter end index...";
	cin >> j;
	if(ds[i][j]!=-1)
		// ds[i][j] -> In O(1) time
		cout << "Smallest from index " <<i <<" to index "<<j << " is "  << ds[i][j] << endl;
	else
		cout << "start index should be <= end index" << endl;
	return 0;
}
