#include<iostream>
using namespace std;

struct Node{
  int v;
  int weight;
  Node* next;
};

struct Adjlist{
Node* head;
  };

  struct Graph{
int size;
Adjlist * array;

  };

Graph* getGraph(int size){
Graph* g = new Graph();
g->size=size;
g->array=new Adjlist[size];
for(int i=0;i<size;i++){
  g->array[i].head=NULL;
}
  return g;
}

Node* newNode(int v, int weight){
Node* n = new Node();
n->v=v;
n->weight=weight;
n->next=NULL;
  return n;
}

void addEdge(int src, int destination,int weight,Graph* g){
Node* n= newNode(destination,weight);
n->next=g->array[src].head;
g->array[src].head=n;

Node* z= newNode(src,weight);
z->next=g->array[destination].head;
g->array[destination].head=z;


}

struct MinHeapNode{
int v;
int dis;

};

struct MinHeap{
  int size;
int * pos;
  MinHeapNode* heap;
};


MinHeapNode newMinHeapNode(int v, int dis){
  MinHeapNode n ;
n.v=v;
n.dis=dis;
return n;

}

void swap(MinHeap* h,int a, int b){
  MinHeapNode temp;
  temp=h->heap[a];
h->heap[a]=h->heap[b];
h->heap[b]=temp;
}
void decreaseKey(MinHeap* h, int v, int dis){
int i=h->pos[v];
h->heap[i].dis=dis;

while(i>=1 && h->heap[i].dis<h->heap[(i-1)/2].dis){
  h->pos[h->heap[i].v]=(i-1)/2;
  h->pos[h->heap[(i-1)/2].v]=i;
swap(h,i,(i-1)/2);
i=(i-1)/2;

}

}

bool isEmpty(MinHeap* h){
  if(h->size==0){
    return true;
  }else
  return false;
}

void minheapify(MinHeap* h, int i)
{
int smallest=i;
int left=2*i+1;
int right=2*i+2;

if(left<h->size && h->heap[left].dis<h->heap[smallest].dis){
  smallest=left;
}


if(right<h->size && h->heap[right].dis<h->heap[smallest].dis){
  smallest=right;
}

if(smallest!=i){
h->pos[h->heap[i].v]=smallest;
h->pos[h->heap[smallest].v]=i;
swap(h,i,smallest);

minheapify(h,smallest);

}



}


MinHeapNode extractMin(MinHeap* h)
{
MinHeapNode root=h->heap[0];

h->heap[0]=h->heap[h->size-1];
h->pos[h->heap[0].v]=0;
--h->size;
minheapify(h,0);
return root;

}

bool isinMinHeap(MinHeap* h,int v){
  if(h->pos[v]< h->size){
    return true;
  }else{
    return false;
  }
}


void Djiks(Graph* g){

int v=g->size;
int d[v];

MinHeap* h= new MinHeap();
h->pos=new int[v];
h->heap=new MinHeapNode[v];
h->size=v;
for(int i=0;i<v;i++){
  h->pos[i]=i;
  h->heap[i]=newMinHeapNode(i,1000);
  d[i]=1000;
}
decreaseKey(h,0,0);
d[0]=0;

  while(!isEmpty(h))
{
  MinHeapNode node= extractMin(h);
int u = node.v;
Node* n =g->array[u].head;
while (n!=NULL) {
  int q = n->v;
if(isinMinHeap(h,q) &&n->weight+d[u]<d[q]){
d[q]=n->weight+d[u];
decreaseKey(h,q,d[q]);
}
  n=n->next;
}

}
for(int k=0;k<v;k++){
  cout << d[k] << " ";
}

}


int main(){
Graph* g=getGraph(9);

addEdge( 0, 1, 4,g);
 addEdge( 0, 7, 8,g);
 addEdge( 1, 2, 8,g);
 addEdge( 1, 7, 11,g);
 addEdge( 2, 3, 7,g);
 addEdge( 2, 8, 2,g);
 addEdge( 2, 5, 4,g);
 addEdge( 3, 4, 9,g);
 addEdge( 3, 5, 14,g);
 addEdge( 4, 5, 10,g);
 addEdge( 5, 6, 2,g);
 addEdge( 6, 7, 1,g);
 addEdge( 6, 8, 6,g);
 addEdge( 7, 8, 7,g);
Djiks(g);

}
