#include<iostream>
#include<vector>
using namespace std;
//void insertElements(vector<int>*,int,int);
void insertElements(vector<int> &v,int n,int times)
{
	for(int i=0;i<times;i++){
                for(int j=0;j<n;j++){
                        v.push_back(j);
                }
        }
}
void deleteElements(vector<int> &v,int n)
{
	for(int i=0;i<n;i++){
		v.erase(v.begin());	
	}
}
void displayElements(vector<int> &v){
	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
		cout << *it << "\t";
	}
}
int main()
{
	vector<int> v;
	cout << "\nInserting Elements\n";
	insertElements(v,10,1);
	cout << "Display Inserted Elements\n";
	displayElements(v);
	cout << "\nDeleting Elements\n";
	deleteElements(v,5);
	cout << "Display Elements after Deletion\n";
	displayElements(v);
	return 0;
}
