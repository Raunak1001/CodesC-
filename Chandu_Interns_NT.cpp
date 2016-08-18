#include<iostream>
using namespace std;

bool CalculateFactors(long long int i){
int count=0;
for(long long int j=2;j*j<=i; j++)
  {
if(j%i==0){
if(j*j==i){
  count++;
}else{
  count +=2;
}

  if(count>=2){
    return true;
  }
}
return false;

  }
}

int main(){

long long int n,a;
cin >> n;
  for(long long int i=0;i<n;i++){
cin >> a;
if(CalculateFactors(a)){
  std::cout << "NO" << std::endl;
}else
std::cout << "YES" << std::endl;

  }
}
