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
	cout << "EMAILS\n";
	for(vector<struct EmailMsg>::iterator it=v.begin();it!=v.end();it++){
		cout << "From:" << it->from << "\n"; //'*(it).to' to access the structure value is not working
                cout << "subject:" << it->subject << "\n";
                cout << "message:" << it->message << "\n";
                cout << "data:" << it->data << "\n";
                cout << "time:" << it->time << "\n\n";
        }
}
//Removes spam emails from the vector
void removeSpam(vector<struct EmailMsg> &v){
	cout << "Checking for SPAM...\n";
	int count=0;
	for(vector<struct EmailMsg>::iterator it=v.begin();it!=v.end();){
		//Removes email with subject starting with 'spam' or 'SPAM'
		if(it->subject.substr(0,4)=="SPAM" || it->subject.substr(0,4)=="spam"){	
			cout << "\nIts a Spam. Removing Spam";
			it = v.erase(it);	//now the iterator points to the next element. so no need to increment it.
			count++;
		}
		else
			it++;
	}
	cout << "\n" << count << " spam(s) removed\n";
}
//Structure of EmailMsg to hold multiple recipients
struct ModifiedEmailMsg{
        vector<string> to;
        string from;
        string subject;
        string message;
        int data;
        int time;
};
//Initialising the 'ModifiedEmailMsg' structure
struct ModifiedEmailMsg createModifiedEmailStructure(vector<string> &to,string from,string subject,string message,int data,int time){
	struct ModifiedEmailMsg e = {to,from,subject,message,data,time};
	return e;
}
//Display the EmailMsgs in a vector v
void displayModifiedEmailStructure(vector<struct ModifiedEmailMsg> &v){
        cout << "MODIFIED EMAIL STRUCTURE - EMAILS\n";
        for(vector<struct ModifiedEmailMsg>::iterator it=v.begin();it!=v.end();it++){
		cout << "To:";
		int noOfRecipients=(it->to).size();
		for(int i=0;i<noOfRecipients;i++)
			cout << (it->to)[i] << " ; ";
		cout << "\nFrom:" << it->from << "\n";
                cout << "subject:" << it->subject << "\n";
                cout << "message:" << it->message << "\n";
                cout << "data:" << it->data << "\n";
                cout << "time:" << it->time << "\n";
		cout << "LAST RECIPIENT  :  " << (it->to)[(it->to).size()-1] << "\n"; //Accessing last recipient
        }
}
int main()
{
	//Vector of 'EmailMsg' structure
	vector<struct EmailMsg> v;
	//Initialize the structure
	struct EmailMsg e;
	e = createEmailStructure("Gowthamgg05@hotmail.com","gowtham.radhakrishna@gmail.com","Hiii","Helllo",2,24);
	//Push it to the vector v
	v.push_back(e);
	e = createEmailStructure("Gowtham","gowtham.radhakrishna@solitontech.com","SPAM This is not a spam","Helllo",2,24);
	v.push_back(e);
	e = createEmailStructure("GowthamGG05@gmail.com","mogith@gmail.com","spam!!!1We wont spam you!!!","Helllo",2,24);
        v.push_back(e);
	//Display EmailMsgs
	displayEmailStructure(v);
	//Remove Spam
	removeSpam(v);
	displayEmailStructure(v);

	//vector of 'ModifiedEmailMsg' structure
	vector<struct ModifiedEmailMsg> m;
	//Initialize the structure for 'ModifiedEmailMsg'
	struct ModifiedEmailMsg me;
	vector<string> recipients;
	recipients.push_back("abc@gmail.com");
	recipients.push_back("xyz@gmail.com");
	recipients.push_back("gowthamgg05@gmail.com");
	me = createModifiedEmailStructure(recipients,"mogith@gmail.com","Have a good day","Good Morning",3,12);
	//Push it to the vector m
	m.push_back(me);
	displayModifiedEmailStructure(m);
}
