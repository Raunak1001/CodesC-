#include<iostream>
#include<set>
using namespace std;

long long int count(long long int n){

long long int count=0;

while(n){

n=n&(n-1);
count ++;

}

return count;

}

int main(){

long long int t,n,k,temp,ans;
multiset<long long int> :: iterator i;
cin >> t;
for(long long int y=0; y<t; y++){
ans=0;
multiset<long long int> s;

cin >> n >>k;

for(long long int q=0;q<n;q++){

cin >> temp;

s.insert(count(temp));


}

i=s.end();
i--;
for(long long int j=0; j<k; j++){
ans=ans+*i;
i--;
}

std::cout << ans << std::endl;  
}



}
