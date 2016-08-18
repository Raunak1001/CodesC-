#include<iostream>
using namespace std;

long long int c=100000007;

long long int power(long long int a, long long int b){
long long int ans=1;
while(b!=0){

  if(b%2==1){
   ans=ans*a%c;

}

a=a*a%c;
b/=2;


}
return ans;
}


long long int fact(long long int m){
if(m%2==0){
  return 1;

}else{
  return 2;
}

}

int main(){


long long int t;

cin >> t;
for(long long int q=0;q<t;q++){

long long int n,m;

cin >> n >> m;

long long int i=n/2;

long long int ans=((power(n-i,m)%c)+(fact(m)%c)*(power(i,m/2)%c)*(power(n-i,m-m/2)%c))%c;

std::cout << ans<< std::endl;

}
}
