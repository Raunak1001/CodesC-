#include<iostream>
using namespace std;


void check(long long int x){




}

int main(){

long long int d,n,x,first,second;

cin >> n >> d;

long long int c[n];
for(long long int i =0; i<n;i++ ){
  cin >> c[i];
}

long long int a[n+1][n+1];

for(long long int i=1;i<n+1;i++){
for(long long int j=i+1;j<=n;j++){

a[i][j]=c[j-1]-c[i-1];

}

}

for(long long int k=0; k<d;k++){
  first=-1;
  second=200000;
cin >>x;

for(long long int i=1; i<=n;i++){

  for(long long int j=i+1;j<=n;j++){
if(a[i][j]==x){
  if((j-i)<second-first)
{
  second=j;
  first=i;
}

}


  }
}

if(first!=-1){

cout << first<<" "<< second<<endl;
  }else{
    cout << first <<endl;

  }
}

for(int i=1 ;i<=n;i++){

for(int j=1;j<=n;j++)
  {
    std::cout << a[i][j] << " ";
  }
  std::cout << endl;
}

}
