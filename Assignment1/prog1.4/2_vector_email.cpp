#include<iostream>
#include<vector>
using namespace std;
struct email{
	string to;
	string from;
	string subject;
	string msg;
	int data;
	int time;
};
int main()
{
	vector<struct email> v;
	struct email e ={"owtham","fsdf","Asasd","asdasdasd",2,3};
	v.push_back(e);
	cout << "hello" << v.size();
	for(vector<struct email>::iterator it=v.begin();it!=v.end();it++){
		cout << "To:" << v[0].to << "\n";
		cout << "From:" << v[0].from << "\n";
		cout << "subject:" << v[0].subject << "\n";
		cout << "msg:" << v[0].msg << "\n";
		cout << "data:" << v[0].data << "\n";
		cout << "time:" << v[0].time << "\n";
	}	
}
