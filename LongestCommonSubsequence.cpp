#include<iostream>
#include<stack>
using namespace std;

int main(){
stack<long long int > s;
  long long int p,q;
long long int * a,*b;
  cin >> p >>q;

    a= new long long int[p];
    b=new long long int[q];
    for(long long int i=0; i<p;i++){
      cin >> a[i];
    }
    for(long long int i=0; i<q;i++){
      cin >> b[i];
    }

  long long int c[p+1][q+1];
    int temp=1;

  for(long long int i=0;i<=p;i++){
    for(long long int j=0;j<=q;j++){
      c[i][j]=0;
    }
  }

  for(long long int i=1; i<= p; i++){

    for(long long int j=1;j<=q;j++){

        if(a[i-1]==b[j-1]){
          c[i][j]=max(c[i-1][j],c[i][j-1])+1;
        }else{
          c[i][j]=max(c[i-1][j],c[i][j-1]);
        }

        }
      }

for(int i=0;i<=p;i++){
  for(int j=0;j<=q;j++){
    std::cout << c[i][j] <<" ";
  }
  std::cout << std::endl;
}

long long int i=p,j=q;

while(i>0 && q>0){

if(c[i-1][j]==c[i][j])
{
i--;
  }else if(c[i][j]==c[i][j-1]){
    j--;
  }else{
    s.push(a[i-1]);
    i--;
    j--;
  }

}
while(!s.empty()){

std::cout << s.top() << " ";
  s.pop();
}


}
