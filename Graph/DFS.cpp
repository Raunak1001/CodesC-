#include<iostream>
#include<list>
#include<stack>
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


  void DFSUtil(int ver,bool* visited,stack<int> &s){


    visited[ver]=true;
    std::cout << ver <<" ";

    list<int>::iterator i;
    for(i=adj[ver].begin();i!=adj[ver].end();++i){
      if(visited[*i]==false){
        DFSUtil(*i,visited,s);

      }
    }
    s.push(ver);


  }

  void DFS(){

    stack<int> s;
    bool visited[v];

    for(int i=0; i<v; i++)
    {
      visited[i]=false;
    }

    for(int i=0;i<v; i++){
      if(visited[i]==false){

        DFSUtil(i,visited,s);

      }

    }
    std::cout <<endl<< "Toplogical Sort"<< std::endl;
    while(!s.empty()){

      cout<<s.top()<<" ";
      s.pop();
    }
    
  }

};


int main(){

  Graph g(6);
  /*  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  */

  g.addEdge(5, 2);
  g.addEdge(5, 0);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);
  cout << "Following is Depth First Traversal\n";
  g.DFS();

  std::cout << endl;


}
