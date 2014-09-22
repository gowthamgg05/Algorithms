#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef struct dimension{
	float x;
	float y;
} Dimension;
typedef struct property{
	string propertyName;
	float price;
} Property;
					      					          
int main(int argc,char **argv)
{
	int noOfProperties;
	float radius,cost,coOrdinates;
	Dimension d[3];
	ifstream fp(argv[1]);
	if(fp)
	{
                fp >> noOfProperties;
		vector<Property> v;
		for(int i=0;i<noOfProperties;i++){
			fp >> coOrdinates;
			if(coOrdinates==1){
				fp >> cost;
				fp >> radius;
				Property p = {"Circle",cost*3.14*radius*radius};
				cout << "circle";
				v.push_back(p);
				continue;	
			}
			if(coOrdinates==2){
				fp >> cost;
				fp >> d[0].x;
				fp >> d[0].y;
				fp >> d[1].x;
				fp >> d[1].y;
				//float length = (d[0].x > d[1].x)?(d[0].x-d[1].x):(d[1].x-d[0].x);
				//float breadth = (d[0].y > d[1].y)?(d[0].y-d[1].y):(d[1].y-d[0].y); 
				float length = abs(d[0].x-d[1].x);
				float breadth = abs(d[0].y-d[1].y);
				Property p = {"Rectangle",cost*length*breadth};
				v.push_back(p);	
				cout << "Rectangle";
				continue;
			}
			if(coOrdinates==3){
				fp >> cost;
				fp >> d[0].x;
                                fp >> d[0].y;
                                fp >> d[1].x;
                                fp >> d[1].y;
				fp >> d[2].x;
				fp >> d[2].y;
				float area = abs(d[0].x*(d[1].y-d[2].y)+d[1].x*(d[2].y-d[0].y)+d[2].x*(d[0].y-d[1].y))/2;
				Property p = {"Triangle",cost*area};
				v.push_back(p);
				cout << "Triangle";
				continue;
			}
		}
		for(vector<Property>::iterator it=v.begin();it!=v.end();it++){
               	        cout << "Property Type : " << it->propertyName << "\n";
                       	cout << "Price of the property : " << it->price << "\n\n";
        	}
		cout << "Asdsad" << v.size();		
	}else{
		cout << "\nFile not found at " << argv[1] << "\nPlease mention the full path of the file";
		cout << "\nSpecify the path in double quotes";
		cout << "\nMake sure the file path doesn't have white space character(s)\n";
	}
	fp.close();
}
