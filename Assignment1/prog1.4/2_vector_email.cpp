#include<iostream>
#include<vector>
using namespace std;
//Structure of EmailMsg
struct EmailMsg{
	string to;
	string from;
	string subject;
	string message;
	int data;
	int time;
};
//Initialising the 'EmailMsg' structure
struct EmailMsg createEmailStructure(string to,string from,string subject,string message,int data,int time){
	struct EmailMsg e ={to,from,subject,message,data,time};
	return e;
}
//Display the EmailMsgs in a vector v
void displayEmailStructure(vector<struct EmailMsg> &v){
	for(vector<struct EmailMsg>::iterator it=v.begin();it!=v.end();it++){
                cout << "To:" << it->to << "\n";                //'*(it).to' to access the structure value is not working       
                cout << "From:" << it->from << "\n";
                cout << "subject:" << it->subject << "\n";
                cout << "message:" << it->message << "\n";
                cout << "data:" << it->data << "\n";
                cout << "time:" << it->time << "\n";
        }
}
//Removes spam emails from the vector
void removeSpam(vector<struct EmailMsg> &v){
	int count=0;
	for(vector<struct EmailMsg>::iterator it=v.begin();it!=v.end();it++){
		if(it->subject.substr(0,4)=="SPAM" || it->subject.substr(0,4)=="spam"){
			cout << "Its a Spam. Removing Spam";
			count++;
		}
	}
	cout << count << " spam(s) removed";
	
}
int main()
{
	//Vector of 'EmailMsg' structure
	vector<struct EmailMsg> v;
	//Initialize the structure
	struct EmailMsg e;
	e = createEmailStructure("Gowtham","gg","spamsdfsdfsdf","Helllo",2,24);
	//Push it to the vector
	v.push_back(e);
	e = createEmailStructure("Gowtham","gg","SPAM measdkf ","Helllo",2,24);
	v.push_back(e);
	//Display EmailMsgs
	displayEmailStructure(v);
	removeSpam(v);
}
