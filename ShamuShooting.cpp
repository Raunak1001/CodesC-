#include<iostream>
#include <iomanip>

using namespace std;

long long int point1,point2;
long double prob1,prob2;

long  double calc(long double n,long double* a,long long int c,long long int point,long double prob){

if(point>=c){
  return prob;
}
if(n==0){
  return -2;
}
 

if(a[c]!=-1){

return a[c];

}else{

a[c]=(prob)*max(calc(n-1,a,c-point,point1,prob1),calc(n-1,a,c-point,point2,prob2));

}

return a[c];

}


int main(){

long long int t,w;
long double n;
cin >> t;


for(long long int q=0;q<t;q++){




cin >> point1 >> point2 >>n>>w>> prob1 >> prob2;
long  double a[w+1];
for(long long int i=0; i<=w; i++){
  a[i]=-1;
}

prob1/=100;
prob2/=100;
a[0]=max(calc(n,a,w,point1,prob1),calc(n-1,a,w,point2,prob2));


cout<<setprecision(6)<<fixed;
std::cout <<a[0] << std::endl;

}


}
