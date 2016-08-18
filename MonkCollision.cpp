#include<iostream>
using namespace std;

int main(){

long long int t,n,count;
bool visited[10];
cin >> t;
for(long long int q=0;q<t;q++){
  count=0;
cin >>n;
long long int a[n];
for(long long int y=0;y<10;y++){
  visited[y]=false;
}
for(long long int k=0; k<n; k++)
{
cin >> a[k];
  if(visited[a[k]%10]){
    count++;
  }else{
    visited[a[k]%10]=true;
  }
}

  std::cout << count << std::endl;
}



}
