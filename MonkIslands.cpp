#include<iostream>
#include<list>
#include<queue>
using namespace std;

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

  void BFS(long long int n){
    bool visited[v+1];
    queue<long long int> q;
    q.push(1);
q.push(-1);
    long long int count=0;
    long long int z;
    if(n==1){
      cout <<"0"<<endl;
      return;
    }

    for(long long int i=1; i<=v; i++)
    {
      visited[i]=false;
    }

    visited[1]=true;
    while(!q.empty()){


      z=q.front();
      q.pop();

if(z==-1){

  count++;
  q.push(-1);
  z=q.front();
  q.pop();

}

      list<long long int> :: iterator i;

      for(i=adj[z].begin(); i!=adj[z].end();i++){
        if(*i==n){
          q=queue<long long int>();
          cout<< count+1<<endl;
          break;
          return;
        }

        if(!visited[*i]){
          visited[*i]=true;
          q.push(*i);
        }

      }




    }


  }

};

int main(){

  long long int t;
  cin >>t;
  for(long long int q=0; q<t; q++){
    long long int n,m,a,b;
    cin >> n >>m;
    Graph g(n);

    for(long long int z=0; z<m;z++)
    {
      cin >> a >> b;
      g.addEdge(a,b);

    }

    g.BFS(n);

  }

}
