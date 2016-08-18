#include<iostream>
#include<set>
using namespace std;

int main(){

  long long int t;
  cin>>t;
  for(long long int q=0; q<t; q++){

    long long int max=-1,min=-1,n;
    multiset<long long int> s;
    multiset<long long int> :: iterator i;


    cin>>n;


    for(long long int k=0;k<n;k++){

      cin >>max;
      s.insert(max);

    }
    long long int a=1,b=1;

    for(i=s.begin(); i!=s.end(); i++)
    {if(*i<0){
      b=a;
      a=a*(*i);
    }
    else if(*i>0){
      max = -1 ;
      b=b*(*i);
      a=a*(*i);
    }else if(*i==0){
      if(a==1){

        min=0;
      }else if(b==1){

        max=0;
      }

    }

  }

  if(max!=0)
  {
    if(b>a){

      max=b;
    }
    else{
      max=a;
    }
  }

  if(min!=0){

    if(b>a){
      min=a;
    }else{
      min=b;
    }
  }
  i=s.begin();
  if(*i<min){
    min=*i;
  }
  i++;
  if(i==s.end()){
i--;
max=min=*i;

  }
std::cout << max<<" "<<min   << std::endl;

}




}
