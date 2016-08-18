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

void addEdge(int src,int destination){

  adj[src].push_back(destination);
  adj[destination].push_back(src);
}


bool DFSUtil(int src,bool* visited, int* parent){

visited[src]=true;

list<int> :: iterator i;
for(i=adj[src].begin(); i!=adj[src].end(); i++)
{
if(visited[*i]){
if(parent[src]!=*i)
  {

    return true;
  }
}
  else{
    parent[*i]=src;
    if(DFSUtil(*i,visited,parent)){
      return true;
    }
  }
}
  return false;
}



void DFS(){
int temp=0;
bool visited[v];
int parent[v];

for(int i=0;i<v;i++){
  visited[i]=false;

}


for(int i=0;i<v;i++){
  if(!visited[i]){
if(DFSUtil(i,visited,parent)){
  temp=1;
  break;
}else{
  temp=0;
}

  }
}

if(temp==1){
  std::cout << "Cycle Found" << std::endl;
}else{
  std::cout << "Cycle Not Found" << std::endl;
}

}



};


int main(){

Graph g(5);

g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(1,3);
g.addEdge(3,4);
g.addEdge(4,2);
g.addEdge(2,1);
g.DFS();


}
