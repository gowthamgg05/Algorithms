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
	for(vector<int>::iterator it = v.begin();it!=v.begin()+n;it++){
		erase(it);	
	}
}
int main()
{
	vector<int> v;
	insertElements(v,10,1);
	deleteElements(v,5);
	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
                cout << *it << "\n";
        }
	cout << "Hello World" << v.size();
	return 0;
}
