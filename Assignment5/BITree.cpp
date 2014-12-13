// C++ code to demonstrate operations of Binary Index Tree
#include <iostream>
#include<vector>
#include <cstdlib>
using namespace std;

// Input array
int arr[] = {1,2,3,4,5,6,7,8,9};
vector<int> v(arr, arr + sizeof arr / sizeof arr[0]);

// BIT Array - Initialization
vector<int> BITree(v.size(),0);
 
// Function for displaying elements
void displayElements(vector<int> v){
	for(int i=0;i<v.size();i++){
		cout << v[i] << "\t";
	}
}

// Function that updates the BIT array from input array value
// k - index of the element in input array
// x - value at index k
void Set(int k,int x){
	k = k + 1;
	while(k <= v.size()){
		// Create a node
		BITree[k] += x;
		// Move to parent node 
		k += (k & -k);	
	}
}

// Function that sums up first k values
int Sum(int k){
	int sum=0;
	k = k + 1;
	while(k > 0){
		sum += BITree[k];
		k -= (k & -k); 	
	}
	return sum;
}

// Function that sums up values inbetween i and kth index
int Sum(int i,int k){
	return Sum(k) - Sum(i-1);
}

// Two arguments - start index(i) and end index(k) 
int main(int argc,char **argv)
{
	int i = atoi(argv[1]);
	int k = atoi(argv[2]);
    	int arr[] = {1,2,3,4,5,6,7,8,9};
    	cout << "Input values" << endl;
	displayElements(v);
	for(int i=0;i<v.size();i++){
		Set(i,v[i]);
	}
	cout << endl << "BIT values"<< endl;
	displayElements(BITree);
	cout << endl <<"Sum upto index " << i << endl;
	cout << Sum(i);
	cout << endl <<"Sum upto index " << k << endl;
        cout << Sum(k);
	cout << endl << "Sum between index "<< i << " and " << k <<endl;
	cout << Sum(i,k) << endl;
    	return 0;
}
