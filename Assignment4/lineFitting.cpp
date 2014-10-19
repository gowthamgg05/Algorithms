#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//Compute slope,intercept
void computeLineFit(vector<int> &x,vector<int> &y,double *slope,double *interceptY){
	//sumX : sum of all values of x
	//sumY : sum of all values of y
	//sumX2 : sum of squares of all values of x
	//sumXY : sum of product of x & y for all values of x and y
	//meanX : Mean of x values
	//meanY : Mean of y values
	double sumX=0,sumY=0,sumXY=0,sumX2=0,meanX,meanY;
	for(int i=0;i<x.size();i++){
		sumX+=x[i];
		sumY+=y[i];
		sumXY+=(x[i]*y[i]);
		sumX2+=(x[i]*x[i]);
	}
	meanX = sumX/x.size();
	meanY = sumY/y.size();
	*slope = (sumXY - sumX * meanY) / (sumX2 - sumX * meanX);
	*interceptY= meanY - (*slope)*meanX;	
}
int main(int argc,char **argv){
	int n;
	double slope,interceptY;
	vector<int> x,y;
	fstream fp(argv[1]);
	if(fp){
		fp >> n;
		int xVal,yVal;
		for(int i=0;i<n;i++){
			fp >> xVal >> yVal;
			x.push_back(xVal);
			y.push_back(yVal);
		}
		computeLineFit(x,y,&slope,&interceptY);
		cout << "y = " << slope << "x + " << interceptY << "\n";
	}
	else{
		cout << "Error: File not found";
	}
}
