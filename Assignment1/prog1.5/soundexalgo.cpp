#include<iostream>
#include<locale> //toupper()
#include<fstream>
#include<vector>
using namespace std;

//Convert to upper case
string convertToUpper(string s){
	string name;
	locale loc;
	for(int i=0;i<s.length();i++)
                name+=toupper(s[i],loc);
	return name;
}

//Removing consecutive duplicates
void removeConsecutiveDuplicates(vector<char> &v){
	vector<char>::iterator i=v.begin();
	i++;
        for(vector<char>::iterator it=i;it!=v.end();){
                if(*it == *(it-1))
                        it = v.erase(it-1);
		else
			it++;
        }
}

//Removing Zeros
void removeZeros(vector<char> &v){
	for(vector<char>::iterator it=v.begin();it!=v.end();){
		//cout << *it;
		if(*it == '0')
			v.erase(it);
		else
			it++;
	}
}

//Resizing the no.of characters to four
void makeItFour(vector<char> &v){
	if(v.size()<4){
		for(int i=v.size();i<4;i++){
			v.push_back('0');
		}
	}
	else if(v.size()>4){
		for(int i=v.size();i>4;i--){
                        v.pop_back();
                }
	}
}

//Display the vector
void display(vector<char> &v){
        for(vector<char>::iterator it=v.begin();it!=v.end();it++){
                cout << *it;
        }
	cout << "\n";
}

//letterDigitmapping file as first argument and name file as second argument
int main(int argc,char ** argv){
	string s,name,line[7],names;
	vector<char> v;
	s = argv[1];
	name = convertToUpper(s);
	//fstream fp1("/home/gowtham/algorithms/Algorithms/Assignment1/prog1.5/namefile.txt");
	fstream fp1(argv[2]);
	if(fp1){
		while(getline(fp1,names))
		{
			name = convertToUpper(names);
			//fstream fp("/home/gowtham/algorithms/Algorithms/Assignment1/prog1.5/letterDigitmapping.txt");
        		fstream fp(argv[1]);
			if(fp){
                		for(int i=0;i<7;i++){
                        		getline(fp,line[i]);
	                        	line[i].erase(1,1);
        	        	}
        		}
        		else{
	        	        cout << "Error in reading file";
		        }
		        v.push_back(name[0]);
		 	for(int i=1;i<name.length();i++){
		                for(int k=0;k<7;k++){
                		        for(int j=0;j<line[k].length();j++){
                                		if(name[i] == line[k][j]){
		                                        v.push_back(line[k][0]);
                		                        break;
                                		}
		                        }
		                }
		        }
        		removeConsecutiveDuplicates(v);
			removeZeros(v);
        		makeItFour(v);
			cout << name << "\t";
			display(v);
			v.clear();
		}
	}
	else{
		cout << "Error in reading file";	
	}
	fp1.close();

}
