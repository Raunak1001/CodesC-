#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

long long int m,n;


    cin>> n >> m;

    int a[m];

long long  int c[m+1][n+1];

    for(int i=0; i<m;i++){

        cin >> a[i];

    }



   for(int i=0;i<=m;i++){

       for(int j=0;j<=n;j++){
           if(i==0 && j==0){
               c[i][j]=1;
           }else{if(i==0){
             c[i][j]=0;
         }else if(j==0){
             c[i][j]=1;
         }else{


           c[i][j]=-1;
         }
                     }
       }

   }



    for(int i=1;i<m+1;i++){

        for(int j=1;j<=n;j++){
            if(a[i-1]<=j){
            long long int k=j/a[i-1];
            int r=j%a[i-1];
        long long     int count =0;

            while(k>=0){
                if(c[i-1][(j-(k*a[i-1]))]!=-1){
      count=count+c[i-1][j-(k*a[i-1])];
              k--;

                }
            }

                c[i][j]=count;
            }
        else if(a[i-1]>j)
        {
            c[i][j]=c[i-1][j];

        }
        }
    }




   cout << c[m][n]<<endl;
    return 0;
}
