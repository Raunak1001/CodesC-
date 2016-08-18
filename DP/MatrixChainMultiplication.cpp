#include<iostream>
using namespace std;


void matrix(int * p,int n)
{
int m[n+1][n+1],s[n+1][n+1];

for(int i=1;i<=n;i++){
  m[i][i]=0;
}

for(int l=2;l<=n;l++){
for(int i=1;i<=n-l+1;i++){
int j=i+l-1;
m[i][j]=1000;
for(int k=i;k<=j-1;k++){

  int q=m[i][k]+m[k+1][j] +p[i-1]*p[k]*p[j];
  if(q<m[i][j]){
m[i][j]=q;
s[i][j]=k;

  }
}

}

}

std::cout << m[1][n] << std::endl;

}
int main(){

int p[]={1,2,3,4};
matrix(p,3);

}
