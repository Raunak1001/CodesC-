#include<iostream>
using namespace std;


long long int count(long long int n){

long long int count=0 ;
while(n){
n=n&(n-1);
count++;

}

return count;

}

int main(){

long long int t,a,b;
cin >> t;
for(long long int q=0;q<t;q++){

cin >> a >>b;

std::cout << count(a^b) << std::endl;


}

}
