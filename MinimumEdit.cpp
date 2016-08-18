#include<iostream>

using namespace std;

int main(){

string a,b;

cin >> a;
cin >> b;
int p=a.length();
int q=b.length();
int c[p+1][q+1];


for(int i=1;i<=p;i++){
  c[i][0]=i;
}

for(int i=1;i<=q;i++){
  c[0][i]=i;
}
c[0][0]=0;

for(int i=1;i<=p;i++){

for(int j=1;j<=q;j++){

if(a[i-1]==b[j-1]){
  c[i][j]=min(c[i-1][j],min(c[i][j-1],c[i-1][j-1]));
}else{
  c[i][j]=min(c[i-1][j],min(c[i][j-1],c[i-1][j-1]))+1;
}



}


}

for(int i=0;i<=p;i++){

for(int j=0;j<=q;j++)
  {
    std::cout << c[i][j] << " ";
  }
  std::cout << endl;
}
std::cout << c[p][q] << std::endl;




}
