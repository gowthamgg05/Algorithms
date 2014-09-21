#include<iostream>
#include<stdlib.h>
using namespace std;
void fibo(int number)
{
	if(number>0 && number < 48){
		int current=1,previous=-1,next=0;
		for(int i=0;i<number;i++){
			next = previous+current;
			cout << next <<"\n";
			previous = current;
			current = next;
		}
	}else{
		cout << "Error : Supported Range 1 to 47";
	}
}
int main(int argc,char *argv[])
{
	cout << "Here is the Fibonacci Series of " << argv[1] << ":\n";
	fibo(atoi(argv[1]));	
}
