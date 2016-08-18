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


void DFSUtil(stack<int> &s,int i,bool* visited){
visited[i]=true;
list<int> :: iterator j;
for(j=adj[i].begin(); j!=adj[i].end(); j++){

if(!visited[*j])
DFSUtil(s,*j,visited);

}

s.push(i);

}


void Topo(){

stack<int> s;
bool visited[v]={false};

for(int i=0;i<v;i++){
  if(!visited[i])
DFSUtil(s,i,visited);
}


while (!s.empty()) {
  cout<< s.top()<< " ";
  s.pop();

}

}




};




int main(){
Graph g(6);

g.addEdge(1,2);
g.addEdge(3,2);
g.addEdge(2,5);
g.addEdge(4,3);
g.addEdge(3,5);
g.addEdge(1,4);

g.Topo();
std::cout << std::endl;



  return 0;
}
