#include<iostream>
#include<vector>
using namespace std;

class PQueue
{ 
	public:
		bool impType;
		vector<int> queue;
		PQueue(bool impTyp){
			impType = impTyp;
		};
		~PQueue(){};
		int size();
		bool IsEmpty();
		void Enqueue(int new_element);
		int RemoveMin();
};
int PQueue::size(){
	return queue.size();
}
bool PQueue::IsEmpty(){
	return (size()==0);
}
void PQueue::Enqueue(int new_element){
	queue.push_back(new_element);
}
int  PQueue::RemoveMin(){
	if(impType==true){
		vector<int> :: iterator minIndex=queue.begin();
		for(vector<int>::iterator i=queue.begin();i!=queue.end();i++){
			if(i==queue.begin())
				minIndex=i;
			if(*i<*minIndex)
				minIndex=i;	
		}
		int minElement = *minIndex;
		queue.erase(minIndex);
		return minElement;
	}
}

int main(){
	PQueue pqueue(true),pqueue1(false);
	pqueue.Enqueue(0);
	pqueue.Enqueue(2);
	pqueue.Enqueue(3);
	pqueue.Enqueue(1);
	pqueue.Enqueue(4);
	pqueue1.Enqueue(0);
        pqueue1.Enqueue(2);
        pqueue1.Enqueue(3);
        pqueue1.Enqueue(1);
        pqueue1.Enqueue(4);
	//cout << pqueue.size();
	//pqueue.RemoveMin();
	//cout << pqueue.size();
	//cout << pqueue.IsEmpty();
	//cout << "\n";
	pqueue1.RemoveMin();
	//heapSort(pqueue1);
	//display(pqueue1);
	//cout << pqueue.impType << "\t" << pqueue1.impType;
}
