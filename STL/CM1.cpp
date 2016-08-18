#include<iostream>
#include<unordered_set>

using namespace std;


int main(){


 long double t;
cin>>t;
for(long double z=0; z<t; z++){
  unordered_multiset<long long int> a;
long double q;
long long int m,n;
cin>>n;
cin>>m;

long double b[m];
for(long double i=0; i<n; i++){
  cin>>q;
  a.insert(q);
}

for(long long int i=0; i<m;i++){
  cin>>q;
  b[i]=q;
}

unordered_multiset<long long int> :: iterator j;
for(long long int i =0; i<m; i++){
j=a.find(b[i]);
if(j!=a.end()){

std::cout << "YES" << std::endl;

}else{
  std::cout << "NO" << std::endl;
}
a.insert(b[i]);
}
}
}
