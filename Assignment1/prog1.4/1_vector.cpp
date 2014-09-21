#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> v(10,0);
	for(vector<int>::iterator i=v.begin();i!=v.end();i++){
		(*i)++;
		cout << "5";
	}
	for(vector<int>::iterator i=v.begin();i!=v.end();i++){
                cout << *i << "\n";
        }
	cout << "Hello World" << v.size();
	return 0;
}
