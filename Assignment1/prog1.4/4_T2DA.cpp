#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(int argc,char **argv)
{
	int noOfProperties;
	ifstream fp(argv[1]);
	/*while(getline(fp,s)){
		cout << s;
	}*/
	/*while(fp >> s){
		cout << s;
	}*/
	if(fp)
	{
                fp >> noOfProperties;
				
	}else{
		cout << "\nFile not found at " << argv[1] << "\nPlease mention the full path of the file";
		cout << "\nSpecify the path in double quotes";
		cout << "\nMake sure the file path doesn't have white space character(s)\n";
	}
	cout << noOfProperties;
	fp.close();
}
