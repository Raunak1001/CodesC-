#include<iostream>
#include<list>
#include<queue>
using namespace std;
long long int parent;

class Graph{

  long long int v;
  list<long long int> *adj;

  public :
  Graph(int v){
    this->v=v;
    adj= new list<long long int>[v+1];
  }

  void addEdge(long long int src, long long int destination){
    adj[src].push_back(destination);
    adj[destination].push_back(src);

  }


  void DFSUtil(long long int ver,bool* visited, long long int** w,long long int count){


    visited[ver]=true;

    list<long long int>::iterator i;
    for(i=adj[ver].begin();i!=adj[ver].end();++i){
      w[parent][*i]=count;
      w[ver][*i]=count;
      if(visited[*i]==false){
        DFSUtil(*i,visited,w,count);

      }
    }




  }


};

int main(){

  long long int t;
  long long int n,m,a,b,count;
  long long int temp=0;

  cin >> t;

  for(long long int y=0; y<t; y++){
    temp=0;
    count=0;

    cin >> n>>m;

    Graph g(n);

    bool visited[n+1];
    long long int ** l;
    l= new long long int*[n+1];

    for(long long int j=1;j<n+1;j++)
    {
      l[j]= new long long int[n+1];
    }

    for(long long int j=1; j<n+1; j++){
      visited[j]=false;
      for(long long int k=1; k<n+1; k++){
        l[j][k]=-1;
      }

    }

    long long int p[n+1],q[n+1];
    for(long long int j=1;j<n+1;j++){

      cin >> p[j];
    }
    for(long long int j=1;j<n+1;j++){

      cin >> q[j];
    }

    for(long long int j=1;j<m+1;j++)
    {
      cin>> a>> b;
      g.addEdge(p[a],p[b]);

    }

    for(long long int j=1; j<n+1;j++ )
    {
      temp=0;
      if(p[j] != q[j]){
        if(!visited[p[j]])
        {parent=p[j];
          count++;
          g.DFSUtil(p[j],visited,l,count);

        }

          for(long long int z=1;z<n;z++){
            if(l[p[j]][z]!=-1){
              if(l[p[j]][z]==l[q[j]][z]){
                temp=1;
                break;
              }

            }

          }

          if(temp==0){
            std::cout << "NO "<< std::endl;
            break;
          }
      }
      else{
        temp=1;
      }

      }
      if(temp==1){
std::cout << "YES" << std::endl;
}
    }

  }
