#include<iostream>

using namespace std;

long long int n,ans;
long long int DFS(long long int shop,long long int item,long long int price,long long int **a,long long int** b)
{



if(shop==(n-1)){

b[shop][item]= a[shop][item];
}




if(b[shop][item]==-1)
{
if(item==1){
  b[shop][item]=min(DFS(shop+1,0,price,a,b),DFS(shop+1,2,price,a,b))+a[shop][item];
}
else if(item==0){
  b[shop][item]=min(DFS(shop+1,1,price,a,b),DFS(shop+1,2,price,a,b))+a[shop][item];
}
else if(item==2){
  b[shop][item]=min(DFS(shop+1,0,price,a,b),DFS(shop+1,1,price,a,b))+a[shop][item];
}


}

  return b[shop][item];






}

int main(){

long long int t;

cin >> t;
long long int price;

for(long long int q=0;q<t;q++){

ans=1000000;
  long long int **a,**b;
price=0;

cin >>n ;

a=new long long int*[n];

b=new long long int*[n];



for(long int i=0;i<n;i++){
  a[i]=new long long int[3];
  b[i]=new long long int[3];

for(int j=0;j<3;j++){
  cin >> a[i][j];
  b[i][j]=-1;
}

}

 DFS(0,0,price,a,b);
price=0;
DFS(0,1,price,a,b);
price=0;
DFS(0,2,price,a,b);



std::cout << min(min(b[0][0],b[0][2]),b[0][1]) << std::endl;
}


}
