#include<iostream>
#include<set>
using namespace std;

int main(){

long long int t,m,n,u,v,w,x,counta,countb;
multiset<long long int> :: iterator z;
multiset<long long int> :: iterator h;

cin >> t;
for(long long int q=0; q<t;q++)
{
  multiset<long long int> s,a;
long long int c[10000],p[10000];

cin >>m >>n;

for(long long int k=0; k<m; k++)
{
cin >> u;
s.insert(u);
cin >> c[u];

}
for(long long int k=0;k <n; k++)
{
cin >> w;
a.insert(w);
cin >> p[w];

}

cin>> v>>x;
if(m>n){
  m=n;
}
z=s.begin();
h=a.begin();
for(long long int k=0; k<m; k++){

if(*z!=*h){
  break;
}
counta++;
if(p[*h]==c[*z]){
  countb++;
}

if(countb >=x){
  break;
}
h++;
z++;

}

if(countb>=x){

  std::cout << "Great" << std::endl;
}else if(counta>= v){
  std::cout << "Good" << std::endl;
}else{
  std::cout << ":(" << std::endl;
}

}

}
