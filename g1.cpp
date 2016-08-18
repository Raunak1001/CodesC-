#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

class Graph{

int v;
Node ** adj;

public:
  Graph(int v){
    this->v=v;
adj=new Node*[v];
for(int i=0;i<v;i++){

adj[i]=NULL;
}
  }

Node* getNode(int data){

Node* n = new Node();
n->data=data;
n->next=NULL;
  return n;
}

void addEdge(int src, int destination){

Node* n = getNode(destination);
if(adj[src]==NULL){
  adj[src]=n;
  return;
}
n->next=adj[src];
adj[src]=n;


}


void Print(int src){

Node* head=adj[src];
while(head!=NULL){
cout << head->data << " ";
  head=head->next;
}

}
void DFSUtil(int q,bool* visited)
{

visited[q]=true;
Node* head=adj[q];
//std::cout << head-> data << std::endl;

while(head!=NULL){

  if(!visited[head->data]){
    std::cout << head->data <<" ";
DFSUtil(head->data,visited);
      }
      head=head->next;


}

}



void DFS(){

bool visited[v];

for(int i =0; i<v; i++){
  visited[i]=false;
}


for(int i=0;i<v;i++){
if(!visited[i]){
std::cout << i << " ";
    DFSUtil(i,visited);

  }
}


}

};


int main(){
Graph g(6);

g.addEdge(0,1);
g.addEdge(0,4);
g.addEdge(1,2);
g.addEdge(1,3);
g.addEdge(1,4);
g.addEdge(2,3);
g.addEdge(3,4);
//g.Print(3);
g.DFS();
}
