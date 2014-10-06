#include <vector>
#include <iostream>
#include<fstream>
using namespace std;
//Swap ith and jth index
void swap(vector<int> &a,int i,int j){
	int temp;
    	temp = a[i];
    	a[i] = a[j];
    	a[j] = temp;
}

//Begining of the vector is chosen as pivot element. Returns the pivot index
int partition(vector<int> &a,int p,int q){
    	int x = a[p];
    	int i = p;
    	for(int j=p+1;j<=q;j++){
        	    if(a[j]<=x){
                	i++;
                	swap(a,i,j);
            	}
    	}
    	swap(a,p,i);
    	return i;
}

//Recursively search whether the pivot index is in the middle of the vector or not
void findMedian(vector<int> &a,int p,int q,int k){
	int index = partition(a,p,q);
    	if(index == k/2)
        	cout << a[index];
    	else if(index > k/2)
        	findMedian(a,p,index-1,k);
    	else if(index < k/2)
        	findMedian(a,index+1,q,k);
}

int main(int argc,char **argv) {
    	int n,k;
	ifstream fp(argv[1]);
	if(fp){
		fp >> n;
		vector<int> v;
		int item;
		for(int i=0;i<n;i++){
			fp >> item;
			v.push_back(item);
		}
		findMedian(v,0,n-1,n);
	}
	else
	{
		cout << "File not found";
	}
}
