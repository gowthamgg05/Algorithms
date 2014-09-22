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
					      					          
float computeAreaOfTriangleWithVertices(float ax,float ay,float bx,float by,float cx,float cy)
{
    /*float A = sqrt((double)(bx-ax) * (bx-ax) + (by-ay) * (by-ay));
    float B = sqrt((double)(bx-cx) * (bx-cx) + (by-cy) * (by-cy));
    float C = sqrt((double)(ax-cx) * (ax-cx) + (ay-cy) * (ay-cy));
    float s = (A + B + C) / 2; 
    float area = sqrt( s * (s-A) * (s-B) * (s-C));
    return area;*/
    return abs(ax*(by-cy)+bx*(cy-ay)+cx*(ay-by))/2;
}

int main(int argc,char **argv)
{
	int noOfProperties;
	float radius,cost,coOrdinates;
	Dimension d[3];
	ifstream fp(argv[1]);
	if(fp)
	{
                fp >> noOfProperties;
		vector<Property> v(noOfProperties);
		for(int i=0;i<noOfProperties;i++){
			fp >> coOrdinates;
			if(coOrdinates==1){
				fp >> cost;
				fp >> radius;
				Property p = {"Circle",cost*3.14*radius*radius};
				v.push_back(p);
				continue;	
			}
			if(coOrdinates==2){
				fp >> cost;
				fp >> d[0].x;
				fp >> d[0].y;
				fp >> d[1].x;
				fp >> d[1].y;
				float length = (d[0].x > d[1].x)?(d[0].x-d[1].x):(d[1].x-d[0].x);
				float breadth = (d[0].y > d[1].y)?(d[0].y-d[1].y):(d[1].y-d[0].y); 
				Property p = {"Rectangle",cost*length*breadth};
				v.push_back(p);	
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
				cout << d[0].x << "\t" << d[0].y << "\n";
				cout << d[1].x << "\t" << d[1].y << "\n";
				cout << d[2].x << "\t" << d[2].y << "\n";
				float area = computeAreaOfTriangleWithVertices(d[0].x,d[0].y,d[1].x,d[1].y,d[2].x,d[2].y);
				//abs(ax*(by-cy)+bx*(cy-ay)+cx*(ay-by))/2;
				area = abs(d[0].x*(d[1].y-d[2].y)+d[1].x*(d[2].y-d[0].y)+d[2].x*(d[0].y-d[1].y))/2;
				cout << area;
				Property p = {"Rectangle",cost*area};
				v.push_back(p);
				//cout << "\nTp" << p.price;
				continue;
			}
		}
		/*for(vector<Property>::iterator it=v.begin();it!=v.end();it++){
               	        cout << "Property Type" << it->propertyName << "\n";
                       	cout << "Price of the property" << it->price << "\n\n";
        	}*/		
	}else{
		cout << "\nFile not found at " << argv[1] << "\nPlease mention the full path of the file";
		cout << "\nSpecify the path in double quotes";
		cout << "\nMake sure the file path doesn't have white space character(s)\n";
	}
	fp.close();
}
