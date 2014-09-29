#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Graph{
	public:
	vector<int> starts;
	vector<int> ends;
	Map<int,vector<int>> Nodes; 
	Graph(vector<int> &starts,vector<int> &ends){
		for(vector<int>::iterator it=starts.begin();it!=starts.end();it++){
			cout << *it;
		}
		Nodes[0]=&starts;
		Nodes[1]=&ends;
		cout << Nodes[0];
	}	
};
int main(){
	int starts[]={1,1,2};
	int ends[]={2,3,3};
	vector<int> v1(starts,starts+(sizeof(starts)/sizeof(starts[0])));
	vector<int> v2(ends,ends+(sizeof(ends)/sizeof(ends[0])));
	Graph g(v1,v2);
}
