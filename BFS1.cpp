#include<iostream>
#include<list>

using namespace std;


class Graph{

struct Node{
  int w;
  int d;
};



int v;
list<Node> *adj;

public :
  Graph(int v){

    this->v=v;
    adj=new list<Node>[v+1];
  }

void addEdge(int src,int destination,int weight){
Node* n = new Node();

n->d=destination;
n->w=weight;
adj[src].push_back(*n);
Node* q= new Node();
q->d=src;
q->w=weight;
adj[destination].push_back(*q);



}

void DFSUtil(long long int j, bool* visited, long long int* dis)
{

visited[j]=true;
list<Node>:: iterator i;
for(i=adj[j].begin(); i!=adj[j].end(); i++){
if(!visited[i->d])
  {

dis[i->d]=dis[j]+i->w;
DFSUtil(i->d,visited,dis);

  }
}



}
void FindPath(){

bool visited[v+1];
long long int dis[v+1];
for(long long int i=1;i<=v; i++){
visited[i]=false;
dis[i]=-1;
  }

dis[1]=0;
DFSUtil(1,visited, dis );
long long int max=-1;
long long int vertex;

for(long long int i=1;i<=v;i++){
if(dis[i]>max){
  max=dis[i];
  vertex=i;
}

dis[i]=-1;
visited[i]=false;

}
max=-1;
dis[vertex]=0;
DFSUtil(vertex,visited, dis );

for(long long int i=1;i<=v;i++){
if(dis[i]>max){
  max=dis[i];
}

}
long long int cost;

if(max<100){
  cost=0;
}else if(max>10000){
  cost=10000;
}
else if(max>1000)
{
  cost=1000;
}else if(max>100){
  cost=100;
}

std::cout <<cost<<" "<< max << std::endl;
}


};





int main(){


long long t;
cin >> t;
for(long long int q=0; q<t ; q++){
long long int n,src,des,w;
cin >>n;
Graph g(n);
for(long long int z=0; z<n-1; z++){

cin >> src;
cin >> des;
cin >> w;
g.addEdge(src,des,w);


}
g.FindPath();

}



}
