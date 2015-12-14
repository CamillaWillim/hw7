#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;


void Kwerte1(const double mu, double r, double s,double* y,double* k);
void Kwerte2(const double mu,double r, double s,double* y4, double* y5,double* k1,double* k2,double* k3,double* k4,double* k5,double* k6,double* k7,double dx);
void stepsize(double* y4,double* y5, const double tol,const double q, double& dx);


int main(){
 
  ofstream out("arenstorfdaten.txt");
  
  double r,s;
  const double mu=0.012277471;
  const double T=17.065216560157;
  double X,dx=1e-3;
  const double tol=1e-5,q=0.4;
  double y4[4],y5[4],k1[4],k2[4],k3[4],k4[4],k5[4],k6[4],k7[4];
  y4[0]=0.994;
  y4[1]=0;
  y4[2]=0;
  y4[3]=-2.00158510637908;
  int i=0;
  
    while(X<=T){
      out << dx << " "<< X << " " <<y4[0]<< " "<<y4[1]<< " " <<y5[0]<< " "<<y5[1]<< endl;
      
      Kwerte2(mu,r,s,y4,y5,k1,k2,k3,k4,k5,k6,k7,dx);
      
      stepsize(y4,y5,tol,q,dx);
      X+=dx;
      cout << dx << " "<< X << endl;
  }
  out.close();
  return 0;
}



  void stepsize(double* y4,double* y5, const double tol,const double q, double& dx){
      double v;
      
                            
      v=abs(y4[0]-y5[0]);
      for (int i=0;i<3;i++){
        if(abs(y4[i+1]-y5[i+1])>v){ 
        v=abs(y4[i+1]-y5[i+1]);}
      }
      
      dx = q*dx*pow((tol/v),(1.0/5.0));
      
}

  
 void kwerte1(const double mu,double r, double s,double* y,double* k){
  r=sqrt(pow(y[0]+mu,2)+pow(y[1],2));
  s=sqrt(pow(y[0]-1+mu,2)+pow(y[1],2));
  
  
  k[0]=y[2];
  k[1]=y[3];
  k[2]=y[0]+2*y[3]-(1-mu)*(y[0]+mu)/pow(r,3)-mu*(y[0]-1+mu)/pow(s,3);
  k[3]=y[1]-2*y[2]-(1-mu)*y[1]/pow(r,3)-mu*y[1]/pow(s,3);
  
} 
  
 void Kwerte2(const double mu,double r, double s,double* y4,double* y5,double* k1,double* k2,double* k3,double* k4,double* k5,double* k6,double* k7,double dx){
    int i;
    double zwischenK[4];
    
    kwerte1(mu,r,s,y4,k1);
    
    for(i=0;i<4;i++)
    zwischenK[i]=y4[i]+(dx/5.0)*k1[i];
    
    kwerte1(mu,r,s,zwischenK,k2);
    
    
    
    for(i=0;i<4;i++)
    zwischenK[i]=y4[i]+(3.0*dx/40.0)*(k1[i]+3*k2[i]);
    
    kwerte1(mu,r,s,zwischenK,k3);
    
    
    
    for(i=0;i<4;i++)
    zwischenK[i]=y4[i]+dx*((44.0/45.0)*k1[i]+(-56.0/15.0)*k2[i]+(32.0/9.0)*k3[i]);
    
    kwerte1(mu,r,s,zwischenK,k4);
    
    
    
    for(i=0;i<4;i++)
    zwischenK[i]=y4[i]+dx*((19372.0/6561.0)*k1[i]+(-25360.0/2187.0)*k2[i]+(64448.0/6561.0)*k3[i]+(-212.0/729.0)*k4[i]);
    
    kwerte1(mu,r,s,zwischenK,k5);
    
    
    for(i=0;i<4;i++)
    zwischenK[i]=y4[i]+dx*((9017.0/3168.0)*k1[i]+(-355.0/33.0)*k2[i]+(46732.0/5247.0)*k3[i]+(49.0/176.0)*k4[i]+(-5103.0/18656.0)*k5[i]);
    
    kwerte1(mu,r,s,zwischenK,k6);
    
    
    for(i=0;i<4;i++)
    zwischenK[i]=y4[i]+dx*((35.0/384.0)*k1[i]+(500.0/1113.0)*k3[i]+(125.0/192.0)*k4[i]+(-2187.0/6784.0)*k5[i]+(11.0/84.0)*k6[i]);

    kwerte1(mu,r,s,zwischenK,k7);
    
    
      
    for(i=0;i<4;i++)
    y5[i]=y4[i]+dx*((5179.0/57600.0)*k1[i]+(7571.0/16695.0)*k3[i]+(393.0/640.0)*k4[i]+(-92097.0/339200.0)*k5[i]+(187.0/2100.0)*k6[i]+(1.0/40.0)*k7[i]);
    
    for(i=0;i<4;i++)
    y4[i]=y4[i]+dx*((35.0/384.0)*k1[i]+(500.0/1113.0)*k3[i]+(125.0/192.0)*k4[i]+(-2187.0/6784.0)*k5[i]+(11.0/84.0)*k6[i]);
  }
   
  
  
  
  


  
