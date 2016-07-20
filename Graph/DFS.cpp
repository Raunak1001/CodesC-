#include<iostream>
#include<list>

using namespace std;

class Graph{


  int v;
  list<int> *adj;

public:

  Graph(int v){
    this->v=v;
    adj=new list<int>[v];
  }

  void addEdge(int src, int destination){

    adj[src].push_back(destination);

  }


  void DFSUtil(int ver,bool* visited){

    visited[ver]=true;
    std::cout << ver <<" ";

    list<int>::iterator i;
    for(i=adj[ver].begin();i!=adj[ver].end();++i){
      if(visited[*i]==false){
        DFSUtil(*i,visited);

      }
    }


  }

  void DFS(){

    bool visited[v];

    for(int i=0; i<v; i++)
    {
      visited[i]=false;
    }

    for(int i=0;i<v; i++){
      if(visited[i]==false){

        DFSUtil(i,visited);

      }

    }

  }

};


int main(){

  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  cout << "Following is Depth First Traversal\n";
  g.DFS();

  std::cout << endl;


}
