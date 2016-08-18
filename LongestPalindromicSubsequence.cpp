#include<iostream>
using namespace std;

int main(){

  string a;
  cin >> a;
  int n= a.length();
a[n]='1';
  int c[n+2][n+2];
  for( int i=0; i<=n+1; i++){
    for(int j=0;j<=n+1;j++)
    {
if(i==j){
  c[i][j]=1;
}else
      c[i][j]=0;
    }

  }

  for( int i=1; i<n+1; i++){

    for(int j=1;j<n+1;j++)
    {
      if(j+i<=n){
      if(a[j-1]==a[j+i-1]){
        c[j][j+i]=c[j+1][i+j-1]+2;
      }else {
        c[j][j+i]=max(c[j+1][j+i],c[j][i+j-1]);

    }
}
}
  }
  for(int i=0;i<=n+1;i++){

  for(int j=0;j<=n+1;j++)
    {
      std::cout << c[i][j] << " ";
    }
    std::cout << endl;
  }

  std::cout << c[1][n] << std::endl;
}
