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

  void BFS(long long int src, bool* visited, long long int * temp1, long long int * temp2, long long int * col){
    queue<long long int> q;
    q.push(src);
    long long int z;
list<long long int > :: iterator i;

if(adj[src].begin()==adj[src].end())
{
*temp1 = *temp1 -1;
return;

}
    while(!q.empty())
    {
      z=q.front();
      q.pop();

      for(i=adj[z].begin(); i!=adj[z].end(); i++){

        if(!visited[*i]){
          visited[*i]=true;
          q.push(*i);
          col[*i]=1-col[z];
          if(col[*i]==0){
            *temp1 =* temp1 +1;


          }else{*temp2 =* temp2 +1;
}

        }

      }

    }

  }

  void getCount(long long int q){
    long long int  *temp1,*temp2,countRed=0,countBlue=0;
    long long int a=0,b=0;
    long long int col[v+1];
    bool visited[v+1];
    for(long long int i=1; i<v+1; i++){
      visited[i]=false;
      col[i]=-1;
    }
    temp1=&a;
    temp2=&b;

    for(long long int i=1;i<=v;i++)
    {
      a=0;
      b=0;

      if(!visited[i])
      {
        col[i]=0;
        *temp1 = *temp1 +1;
        visited[i]=true;
        BFS(i,visited,temp1,temp2,col);
        if(*temp1>*temp2){
          if(countRed>countBlue)
          {
            countRed =countRed+ *temp1;
          }else{countBlue=countBlue + *temp1;

          }
        }else{
          if(countRed>countBlue)
          {
            countRed =countRed + *temp2;
          }else{countBlue = countBlue + *temp2;}

        }

      }

    }
    if(countRed > countBlue)
    {std::cout << "Case "<< q+1 << ": "<< countRed << std::endl;
    }
    else
    std::cout <<"Case "<< q+1<<": "<< countBlue << std::endl;

  }

};


int main(){
  long long int t;
  cin >> t;

  for(long long int q=0; q<t; q++){

    long long int n,a,b;
    cin >>n;
    Graph g( 20000);
    for(long long int i=0; i<n; i++){
      cin >> a;
      cin >> b;

      g.addEdge(a,b);
    }
    g.getCount(q);

  }




}
