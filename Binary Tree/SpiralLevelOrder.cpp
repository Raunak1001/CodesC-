#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct Node{
  int data;
  Node * left;
  Node* right;
};

Node* getNewNode(int data){
  Node* n= new Node();
  n->data=data;
  n->left=NULL;
  n->right=NULL;
  return n;

}

Node* Insert(int data, Node* head)
{
  Node* n =getNewNode(data);

  if(head==NULL){

    head=n;
    return head;
  }

  Node* temphead =head;
  Node *prev;
  while(head!= NULL){
    prev=head;
    if(head->data<data){
      head=head->right;

    }
    else{
      head=head->left;
    }

  }

  if(prev->data<data){
    prev->right=n;
  }else
  prev->left=n;

  return temphead;

}

void printSpiralUtil(stack<Node*> &s, queue<Node*> &q){
Node* n;

  while(!q.empty() || !s.empty()){
    while(!q.empty()){

      n=q.front();
      q.pop();
      std::cout << n->data <<" ";

      if(n->left!=NULL)
      s.push(n->left);
      if(n->right!=NULL)
      s.push(n->right);


    }
    std::cout <<endl;
    while(! s.empty()){
      n=s.top();
      s.pop();

      std::cout << n->data <<" ";

      if(n->left!=NULL)
      q.push(n->left);
      if(n->right!=NULL)
      q.push(n->right);



    }
    std::cout<<endl;
  }
}

void PrintSpiral(Node* head){

  stack<Node* > s;
  queue<Node*> q;

  if(head==NULL){
    return;
  }

  std::cout << head->data <<endl;

  if(head->left!=NULL)
  q.push(head->left);
  if(head->right!= NULL)
  q.push(head->right);

  printSpiralUtil(s,q);


}

int main(){
  Node * head=NULL;
  head=Insert(9,head);
  head=Insert(2,head);
  head=Insert(10,head);
  head=Insert(6,head);
  head=Insert(7,head);
  head=Insert(5,head);
  head=Insert(1,head);
  PrintSpiral(head);


}
