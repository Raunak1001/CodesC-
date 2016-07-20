#include<iostream>
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

void path(Node* head, int* a, int len){
  Node* temphead= head;
  if(temphead==NULL){
    return;
  }



  a[len]=temphead->data;

  if(temphead->left== NULL && temphead->right ==NULL)
  {

    for(int i=0; i<=len;i++){
      std::cout << a[i] <<" ";

    }
    std::cout <<endl;

    len--;
  }
  else{
    len++;
    path(head->left,a,len);
    path(head->right,a,len);


  }



}


int main(){

  Node * head=NULL;
  int a[10];
  int len=0;

  head=Insert(9,head);
  head=Insert(2,head);
  head=Insert(8,head);
  head=Insert(6,head);
  head=Insert(7,head);
  head=Insert(5,head);
  head=Insert(1,head);

  path(head,a,len);

}
