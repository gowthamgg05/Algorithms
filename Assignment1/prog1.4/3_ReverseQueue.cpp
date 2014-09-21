#include<iostream>
#include<queue>
using namespace std;
void swap(int *first,int *last){
	int temp;
	temp = *first;
	*first = *last;
	*last = temp;
}
void reverseQueue(queue<int> &q){
	int *first = &q.front();
	int *last = &q.back();
	while(first<last){
		swap(first,last);
		first++;
		last--;
	}
}
int main()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(33);
	
                int *first = &q.front();
                int *last = &q.back();
                while(first<=last){
                        cout << *first << "\n";
                        first++;
                }
        

	reverseQueue(q);

		int *f = &q.front();
        	int *l = &q.back();
        	while(f<=l){
                	cout << *f << "\n";
			f++;
        	}
	
	cout << "HEllo";
}
