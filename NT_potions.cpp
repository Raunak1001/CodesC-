#include<iostream>
#include<cstring>

using namespace std;

long long int calculatepotion(long long int i,long long int j,long long int v,long long int b)
{

long long int n=i-j;

 for(long long int k=0;k<n;k++){

v=(v*v)%b;


 }
return v%c;

}


int main(){

long long int a,b;
cin >> a>>b;

long long int lastpotion=a,ans=0;
long long int lastInt=0;

string s;

cin >> s;
long long int n=s.length();
for(long long int k=0; k<n; k++){
if(s[k]=='1'){
    lastpotion=calculatepotion(k,lastInt,lastpotion,b);
lastInt=k;
  ans=(ans+lastpotion)%c;
}
}

std::cout << ans << std::endl;

}
