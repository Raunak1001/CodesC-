#include<iostream>
#include <set>
using namespace std;

int main(){

long long int t;
cin >>t;
long long int n,k,z,count;
multiset<long long int > :: iterator i;
multiset<long long int > :: iterator j;

for(long long int q=0;q<t;q++){
count=0;
cin >> n >>k;

multiset<long long int > a,b;
for(long long int y=0; y<n; y++)
{
cin >> z;
a.insert(z);
}

i=a.begin();
j=a.end();
j--;
  if(i==j){
cout<<"0"<<endl;
cout<<"Chick magnet Jhool!"<<endl;
    return 0;
  }

while(count<n/2){

b.insert((*i)+(*j));
i++;
j--;
count++ ;
  }

i=b.begin();
j=b.end();
j--;
 n=(*j)-(*i);
std::cout << n << std::endl;
 if(n<k){
std::cout << "Chick magnet Jhool!" << std::endl;

 }else if(n>k)
{
  std::cout << "No more girlfriends!" << std::endl;
}else{
  std::cout << "Lucky chap!" << std::endl;
}

}
return 0;


}
