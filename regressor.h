#include <iostream>
#include<cmath>
using namespace std;
#include"vector.h"
#include"algorithm.h"
//  
double linear_regression(vector<double> x,vector<double> y,int n,int poch,double test_value)
{
    vector<double>error;             // array to store all error values
    double err;
    double b0 = 0;                   //initializing b0
    double b1 = 0;                   //initializing b1
    double alpha = 0.01; 
    for (int i = 0; i < n*poch; i ++) 
    {   // since there are 5 values and we want 4 epochs so run for loop for 20 times
        int idx = i % n;              //for accessing index after every epoch
        double p = b0 + b1 * x[idx];  //calculating prediction
        err = p - y[idx];              // calculating error
        b0 = b0 - alpha * err;         // updating b0
        b1 = b1 - alpha * err * x[idx];// updating b1
    // printing values after every updation
        error.push_back(err);
    }

sort(error.begin(),error.end());//sorting based on error values
//cout<<"Final Values are: "<<"B0="<<b0<<" "<<"B1="<<b1<<endl;
return b0+b1*test_value;  

}

int logistic_regression(vector<double> x1,vector<double>x2,vector<int>y,int epoch,int n,double test1,double test2)
{
vector<double>error; // for storing the error values
double err;    // for calculating error on each stage
double b0 = 0; // initializing b0
double b1 = 0; // initializing b1
double b2=  0; // initializing b2
double alpha = 0.01; // initializing our learning rate
double  e = 2.71828;
  
/*Training Phase*/

for (int i = 0; i < epoch*n; i ++) 
{ //Since there are 10 values in our dataset and we want to run for 4 epochs so total for loop run 40 times
    int idx = i % n;   //for accessing index after every epoch
    double p = -(b0 + b1 * x1[idx]+ b2* x2[idx]); //making the prediction
    double pred  = 1/(1+ pow(e,p)); //calculating final prediction applying sigmoid
    err = y[idx]-pred;  //calculating the error
    b0 = b0 - alpha * err*pred *(1-pred)* 1.0;   //updating b0
    b1 = b1 + alpha * err * pred*(1-pred) *x1[idx];//updating b1
    b2 = b2 + alpha * err * pred*(1-pred) * x2[idx];//updating b2
    //cout<<"B0="<<b0<<" "<<"B1="<<b1<<" "<<"B2="<<b2<<" error="<<err<<endl;// printing values after every step
    error.push_back(err);
    }
//custom sort based on absolute error difference
  
/*Testing Phase*/

double pred=b0+b1*test1+b2*test2; //make prediction
cout<<"The value predicted by the model= "<<pred<<endl;
if(pred>0.5)
pred=1;
else
pred=0;
cout<<"The class predicted by the model= "<<pred;
return pred;
}
