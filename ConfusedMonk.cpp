#include<iostream>
using namespace std;

long long int GCD(long long int a,long long int b){
  if(b==0){
    return a;
  }else
  return GCD(b,a%b);
}

void  calculateExponent(long long int a, long long int b, long long int c){
  long long int ans=1;
  while(b!=0){

    if(b%2==1){

      ans=(ans*a)%c;
      a=(a*a)%c;
    }
    else{
      a=(a*a)%c;
    }
    b/=2;
  }
  std::cout << ans << std::endl;

}
int main(){
  long long int exponent=1000000007;

  long long int n;
  cin >> n;


  long long int a[n],gcd=0,product=1;

  for(long long int k=0; k<n; k++){
    cin >> a[k];
    gcd=GCD(a[k],gcd);
    product=product*a[k]%(exponent);
  }

  calculateExponent(product,gcd,exponent);

}
