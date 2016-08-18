#include <iostream>
using namespace std;

void Pallindrome(string s, long long int **a,long long int t){

  for(int l = 2; l <= t; l++){
              for(int i = 0; i < t-l + 1; i++){
                  int j = i + l - 1;

if(l==2 && s[i]==s[j] ){
  a[i][j]=1;
}else if(s[i]==s[j]){
  if(a[i+1][j-1]==1){

    a[i][j]=1;
  }else{
      a[i][j]=0;
  }
}else{
  a[i][j]=0;
}

                }
                }


}

long long int palli (long long int ** a, long long int l, long long int r)
{
  if(l>r){
    swap(l,r);
  }
long long int count=0;

for(long long int i=l;i<=r;i++){
  for(long long int j=l; j<=r; j++){
    if(a[i][j]==1){
      count ++;
    }
  }
}

cout << count <<endl;
return count;

}
int main()
{
   long long int t;
   cin >> t;
   string s;
long long int q, l,r,x,y;
cin >> s;
cin >> q >>l >>r >>x >>y;

long long int** a;
a=new long long int*[t];
for(long long int i=0;i<t;i++){
  a[i]=new long long int[t];
}
for(long long int i=0;i<t;i++){
  for(long long int j=0; j<t; j++ ){

if(i==j){
  a[i][j]=1;
}else{
    a[i][j]=0;
  }
}
}
Pallindrome(s,a,t);

long  long int A;

A=palli(a, l-1, r-1);

for(long long int i=1;i<q;i++){
l= ((A * l + x) % t) + 1;
r= ((A * r + y) % t) + 1;
A=palli(a, l-1, r-1);

}
for(long long int i=0;i<t;i++){
  for(long long int j=0; j<t; j++ ){
    cout << a[i][j] << " ";
  }
  cout << endl;
}



   }
