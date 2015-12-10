#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;


void Kwerte(const double mu, double s, double r,double* y,double* k) 


int main(){
 
  ofstream out("arenstorfdaten.txt");
  
  double r,s;
  const double mu=0.012277471;
  const double T=T=17.065216560157;
  double y[6],k1[6],k2[6],k3[6],k4[6],k5[6];
  y[0]=0.994;
  y[1]=0;
  y[2]=0;
  y[3]=0;
  y[4]=-2.00158510637908;
  y[5]=0;
  
  kwerte(mu,r,s,y,k1)
  
  
  out.close();
  return 0;
}

void Kwerte(const double mu,double r, double s,double* y,double* k){
  r=sqrt(pow(y[0]+mu,2)+pow(y[1],2)+pow(y[2],2));
  s=sqrt(pow(y[0]-1+mu,2)+pow(y[1],2)+pow(y[2],2));
  
  
  k[0]=y[3];
  k[1]=y[4];
  k[2]=y[5];
  k[3]=y[0]+2*[4]-(1-mu)(y[0]+mu)/pow(r,3)-mu*(y[0]-1+mu)/pow(s,3);
  k[4]=y[1]-2*x[3]-(1-mu)*y[1]/pow(r,3)-mu*y[1]/pow(s,3);
  k[5]=-(1-mu)*y[2]/pow(r,3) - mu*y[2]/pow(s,3);
  
}