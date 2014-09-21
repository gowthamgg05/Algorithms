#include<iostream>
#include<vector>
using namespace std;
void insertElements(vector<int>*,int,int);
void insertElements(vector<int> &v,int n,int times)
{
        for(int i=0;i<times;i++){
                for(int j=0;j<n;j++){
                        v.push_back(j);
                }
        }
}
int main()
{
	vector<int> v;
	insertElements(v,10,1);
	for(vector<int>::iterator i=v.begin();i!=v.end();i++){
                cout << *i << "\n";
        }
	cout << "Hello World" << v.size();
	return 0;
}
