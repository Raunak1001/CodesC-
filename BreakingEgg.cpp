#include<iostream>
using namespace std;

int main(){

int n,f;
cin >> n;
cin >> f;

int c[n+1][f+1];

for(int i=0;i<=n;i++){
c[i][0]=0;
  }

  for(int i=0;i<=f;i++){
  c[0][i]=0;
c[1][i]=i;
      }




int ans,temp;

for(int i=2;i<=n;i++){
  for(int j=1;j<=f;j++){
    ans=1000;
    temp=1;
for(int k=1;k<j;k++){

  temp=1+max(c[i-1][k-1],c[i][j-k]);

if(temp<ans){
  ans=temp;
}

}
if(temp<ans){
  c[i][j]=temp;
}else
c[i][j]=ans;

  }
}

for(int i=0;i<=n;i++){

for(int j=0;j<=f;j++)
  {
    std::cout << c[i][j] << " ";
  }
  std::cout << endl;
}
cout << c[n][f] << endl;

}
