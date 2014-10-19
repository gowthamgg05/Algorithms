#include<iostream>
#include<vector>
using namespace std;

// Priority Queue
template <class T>
class PQueue
{ 
	public:
		bool impType;	// Whether to use unsorted array or binary heap implementation
		vector<T> queue;	
		PQueue(bool impTyp){	// Constructor for implementation type initialization	
			impType = impTyp;
		};
		~PQueue(){};
		int size();	// Returns size of Priority queue
		bool IsEmpty();		// Returns true if Priority queue is empty
		void Enqueue(T new_element);	// Adds element to the end of the queue
		T RemoveMin();	// Removes less priority element - In this case, minimum value is the lowest priority element
		void display();	
};

template <class T>
int PQueue<T>::size(){
	return queue.size();
}
template <class T>
bool PQueue<T>::IsEmpty(){
	return (size()==0);
}
template <class T>
void PQueue<T>::Enqueue(T new_element){
	queue.push_back(new_element);
}

int leftChild(int i){
        return i*2+1;
}
//HeapSort - Finding right child
int rightChild(int i){
        return i*2+2;
}
//HeapSort - Finding parent
int parent(int i){
        return (i-1)/2;
}
//HeapSort - Swap two template elements
template <class T>
void swap(vector<T> &v,int firstIndex,int secondIndex){
        T temp;
        temp = v[firstIndex];
        v[firstIndex] = v[secondIndex];
        v[secondIndex] = temp;
}
//HeapSort - To maintain the heap property
template <class T>
void heapify(vector<T> &v,int i,int heapSize){
        int l = leftChild(i);
        int r = rightChild(i);
        int largest;
        if(l<=heapSize && v[i]>v[l])
                largest = l;
        else
                largest = i;
        if(r<=heapSize && v[largest]>v[r])
                largest = r;
        if(largest!=i){
                swap(v,largest,i);
                heapify(v,largest,heapSize);
        }
}
//HeapSort - Builds a heap from the array by calling Heapify
template <class T>
void buildHeap(vector<T> &v){
        int heapSize = v.size()-1;
        for(int i=(v.size()-2)/2;i>=0;i--)
        {
                heapify(v,i,heapSize);
        }
}

// Priority Queue - Remove Minimum
template <class T>
T PQueue<T>::RemoveMin(){
	if(impType==true){
		int minIndex=0;
		for(int i=0;i<size();i++){
			if(i==0)
				minIndex=i;
			if(queue[i]<queue[minIndex])
				minIndex=i;	
		}
		T minElement = queue[minIndex];
		queue.erase(queue.begin()+minIndex);
		return minElement;
	}
	else
	{
		buildHeap(queue);
        	int heapSize=size()-1;
		T minElement = queue[0];
		heapify(queue,0,heapSize);
		heapSize--;	
		queue.erase(queue.begin());
		return minElement;
	}
}
template <class T>
void PQueue<T>::display(){
	for(int i=0;i<size();i++){
		cout << queue[i] << "\t";
	}
}
int main(){
	
	// unsorted array as priority queue - arg : true
	PQueue<int> pqueueArray(true);
	// heap as priority queue - arg : false
	PQueue<char> pqueueHeap(false);
	pqueueArray.Enqueue(0);
	pqueueArray.Enqueue(2);
	pqueueArray.Enqueue(3);
	pqueueArray.Enqueue(1);
	pqueueArray.Enqueue(4);
	pqueueArray.Enqueue(12);
	pqueueArray.Enqueue(7);
	pqueueHeap.Enqueue('g');
        pqueueHeap.Enqueue('o');
        pqueueHeap.Enqueue('w');
        pqueueHeap.Enqueue('t');
        pqueueHeap.Enqueue('h');
	pqueueHeap.Enqueue('a');
	pqueueHeap.Enqueue('m');
	// Repeat for three iterations
	for(int i=0;i<3;i++){
		cout << "\n\nunsorted array : ";
		pqueueArray.display();
		cout << "\nbinary heap    : ";
		pqueueHeap.display();
		cout << "\nunsorted array : size - " << pqueueArray.size();
		cout << "\nbinary heap    : size - " << pqueueHeap.size();
		cout << "\nunsorted array : Remove Min - " << pqueueArray.RemoveMin();
        	cout << "\nbinary heap    : Remove Min - " << pqueueHeap.RemoveMin();
		cout << "\nunsorted array : ";
        	pqueueArray.display();
        	cout << "\nbinary heap    : ";
        	pqueueHeap.display();
	}
}
	
