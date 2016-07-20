#include<iostream>
#include<list>

using namespace std;

class Graph{

  int v;
  list<int> *adj;

public:

  Graph(int v){

    this->v=v;
    adj= new list<int>[v];
  }


  void addEdge(int src, int destination)
  {
    adj[src].push_back(destination);

  }

  bool isCyclic(int ver,bool* grey,bool* white){


    white[ver]=false;
    grey[ver]=true;
    list<int> ::iterator i;

    for(i=adj[ver].begin();i!=adj[ver].end();++i){

      if(white[*i]){
        if(isCyclic(*i,grey,white)){
          return true;
        }

      }else if(grey[*i]){

        return true;
      }

    }

    grey[ver]=false;
    return false;

  }


  bool checkCycle(){

    bool grey[v],white[v];

    for(int i = 0; i<v; i++){

      grey[i]=false;
      white[v]=true;

    }

    for(int i=0; i<v; i++){
      if(white[i]==false)
      {if(isCyclic(i,grey,white))
        return true;

      }

    }

    return false;
  }

};

int main(){

  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  //   g.addEdge(1, 2);
  //   g.addEdge(2, 0);
  g.addEdge(2, 3);
  //   g.addEdge(3, 3);

  if(g.checkCycle())
  cout << "Graph contains cycle\n";
  else
  cout << "Graph doesn't contain cycle\n";
  return 0;

}
