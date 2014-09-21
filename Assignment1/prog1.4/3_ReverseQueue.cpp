#include<iostream>
#include<queue>
#include<stdlib.h>	//rand()
using namespace std;
//Swap by reference - inorder to get reflected in the original queue
void swap(int *first,int *last){
	int temp;
	temp = *first;
	*first = *last;
	*last = temp;
}
//Reverse queue
void reverseQueue(queue<int> &q){
	int *first = &q.front();	// get the address of first element in the queue
	int *last = &q.back();		// get the address of last element in the queue
	while(first<last){
		swap(first,last);	// call swap(int*,int*)
		first++;		
		last--;
	}
}
//Display the elements of the queue
void displayQueue(queue<int> &q){
	int *first = &q.front();
        int *last = &q.back();
        while(first<=last){
        	cout << *first << "\t";
                first++;
        }
}
int main()
{
	//Declare queue
	queue<int> q;
	//Initialise it
	for(int i=0;i<10;i++){
		q.push(rand() % 100);
	}
	cout << "Queue Elements...\n";
	//Display the queue
	displayQueue(q);
	//Reverse it
	reverseQueue(q);
	cout << "\nQueue Elemets after reversal...\n";
	//Display it again
	displayQueue(q);
}
