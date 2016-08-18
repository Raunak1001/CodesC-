#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long long int sum(long long int n){
    return n*(n+1)/2;
}

int main() {


    long long int n,count=1,ans=0;
    cin >> n;

    long long int a[n];
    for(long long int i =0;i<n;i++){

        cin >> a[i];
    }
    long long int i=0;
    if(n==1){
      ans=1;
    }
   while(i<n-1){
       if((i+1)<n && a[i+1]<a[i]){

           while((i+1)<n && a[i]>a[i+1]){
               count++;
           i++;
           }
           ans=ans+sum(count);
           count=1;

       }
       if((i+1)<n && a[i]<a[i+1]){
           while( (i+1)<n && a[i]<a[i+1]){

             count++;
           i++;
                  }

          if((i+1)<n && a[i]>a[i+1]){
           count--;
           ans=ans+sum(count);
              count=1;}
           else{
               ans=ans+sum(count);
               count=0;
           }
       }
       if((i+1)<n && a[i]==a[i+1]){
           while((i+1)<n && a[i]==a[i+1] ){
               ans++;
               i++;
           }

       }



   }
    cout<<ans<<endl;
    return 0;
}
