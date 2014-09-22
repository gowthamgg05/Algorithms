#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>	//abs()
using namespace std;

//Structure to store co-ordinates
typedef struct dimension{
	float x;
	float y;
} Dimension;

//Structure to store property information
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
                //No.of properties
		fp >> noOfProperties;
		vector<Property> v;
		for(int i=0;i<noOfProperties;i++){
			//No.of co-ordinates
			fp >> coOrdinates;
			//Circle
			if(coOrdinates==1){
				fp >> cost >> radius;
				Property p = {"Circle",cost*3.14*radius*radius};
				v.push_back(p);
				continue;	
			}
			//Rectangle
			if(coOrdinates==2){
				fp >> cost >> d[0].x >> d[0].y >> d[1].x >> d[1].y;
				float length = abs(d[0].x-d[1].x);
				float breadth = abs(d[0].y-d[1].y);
				Property p = {"Rectangle",cost*length*breadth};
				v.push_back(p);	
				continue;
			}
			//Triangle
			if(coOrdinates==3){
				fp >> cost >> d[0].x >> d[0].y >> d[1].x >> d[1].y >> d[2].x >> d[2].y;
				float area = abs(d[0].x*(d[1].y-d[2].y)+d[1].x*(d[2].y-d[0].y)+d[2].x*(d[0].y-d[1].y))/2;
				Property p = {"Triangle",cost*area};
				v.push_back(p);
				continue;
			}
		}
		for(vector<Property>::iterator it=v.begin();it!=v.end();it++){
               	        cout << "Property Type : " << it->propertyName << "\n";
                       	cout << "Value of the property : " << it->price << "\n\n";
        	}
	}else{
		cout << "\nFile not found at " << argv[1] << "\nPlease mention the full path of the file";
		cout << "\nSpecify the path in double quotes";
		cout << "\nMake sure the file path doesn't have white space character(s)\n";
	}
	fp.close();
}
