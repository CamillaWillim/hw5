#include<iostream>
#include<cmath>

using namespace std;


void euler(int N,double const dt, double* yfa, double* yfn, double* yba, double* ybn);

main(){
  
  double const dt1=M_PI/20, dt2=M_PI/100;
  double yfa[2],yfn[2],yba[2],ybn[2];
  double N1 = 20*M_PI/dt1,N2=20*M_PI/dt2;

  euler(N1,dt1,yfa,yfn,yba,ybn);
  
 return 0; 
}

void euler(int N,double const dt, double* yfa, double* yfn, double* yba, double* ybn){
  yfa[1]=1;
  yfa[2]=0; 
  yba[1]=1;
  yba[2]=0; 
  
  for(int i=0; i<N;i++){
    cout << i*dt << "\t" << yfn[1] << "\t" << ybn[1] << endl;
    //forward
    yfn[1] = yfa[1] + dt*yfa[2];
    yfn[2] = yfa[2] - dt*yfa[1];
    
    yfa[1]=yfn[1];
    yfa[2]=yfn[2];
    //backward
    ybn[1] = (yba[1] + dt*yba[2])/(1+pow(dt,2));
    ybn[2] = (yba[2] - dt*yba[1])/(1+pow(dt,2));
    yba[1]=ybn[1];
    yba[2]=ybn[2];
    }
  
}
   