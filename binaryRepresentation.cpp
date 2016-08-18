#include<iostream>
using namespace std;


int main(){

int A=5;

string a="";
   while(A!=0){
   if(A%2==0){

       a.insert(0,"0");

   }else{

       a.insert(0,"1");
   }
   A/=2;

}


cout << a<< endl;
}
