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

  void BFS(long long int* parent){


    bool visited[v+1];
    queue<long long int> q;
    q.push(1);
    long long int count=0;
    long long int z;

    for(long long int i=1; i<=v; i++)
    {
      visited[i]=false;
    }
    list<long long int> :: iterator i;
    visited[1]=true;
    while(!q.empty()){


      z=q.front();
      q.pop();

      for(i=adj[z].begin(); i!=adj[z].end();i++){

        if(!visited[*i]){
          parent[*i]=z;
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
  Graph g(t);
  long long int parent[t+1];
  int long long u,v;
  for(long long int q=0; q<t-1; q++){

    cin >> u >>v;
    g.addEdge(u,v);

  }
  g.BFS(parent);

  long long int q,a,b;

  cin >> q;

  for(long long int i=0; i<q;i++){
    cin >>a >>b;
    if(a==1){

      cout<<a<<" parent of "<<b<<endl;


    }else if(b==1){

      cout<<b<<" parent of "<<a<<endl;

    }else if(parent[a]==b){

      cout<<b<<" parent of "<<a<<endl;

    }else {

      cout<<a<<" parent of "<<b<<endl;
    }
  }





}
