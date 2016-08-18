#include<iostream>
#include<set>
using namespace std;

int main(){

long long int t,n,a,b,count;

multiset<long long int> :: iterator i;

cin >> t;

for(long long int q=0; q<t; q++){
  count=0;
multiset<long long int> s;
cin >> n;

for(long long int y=0; y<n; y++)
{
cin >> a >> b;

if(a!=b){

i=s.find(b);
s.insert(a);
if(i==s.end()){
  count++;
}else{
  s.erase(i);
}


}

}


std::cout << count << std::endl;


}


}
