#include<iostream>
#include<vector>	
#include<stdlib.h>	//rand()
using namespace std;
//Insert 'n' elements 'times' times to the vector 'v'
void insertElements(vector<int> &v,int n,int times)
{
	for(int i=0;i<times;i++){
                for(int j=0;j<n;j++){
			//push_back() for vector has Amortised Constant time complexity.
			//(ie) Average Time taken per Operation if the operation repeats huge no.of times
			//Amortised time per insertion is O(1)
			/*reference:
				http://stackoverflow.com/questions/200384/constant-amortized-time
                        	http://en.cppreference.com/w/cpp/container/vector/push_back
			*/
			v.push_back(rand() % 100);
                }
        }
}
//Delete fist 'n' elements from the vector 'v'
void deleteElements(vector<int> &v,int n)
{
	//Deleting it one by one
	for(int i=0;i<n;i++){
		v.erase(v.begin());	
	}
}
//Display the elements in vector 'v'
void displayElements(vector<int> &v){
	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
		cout << *it << "\t";
	}
}
int main()
{
	vector<int> v;
	cout << "\nInserting 10 Elements once\n";
	insertElements(v,10,1);
	cout << "Display Inserted Elements\n";
	displayElements(v);
	cout << "\nDeleting Elements\n";
	deleteElements(v,5);
	cout << "Display Elements after Deletion\n";
	displayElements(v);
	cout << "\nInserting 10000000 Elements 10 times\n";
        insertElements(v,10000000,10);
        cout << "Display Inserted Elements\n";
        displayElements(v);
	return 0;
}
