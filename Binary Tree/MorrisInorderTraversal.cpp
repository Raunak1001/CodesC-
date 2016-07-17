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

Node* findPred(Node* n){
  Node* current=n;
  n=n->left;

  while(n-> right != NULL && n->right!=current)
  {
    n=n->right;
  }
  return n;
}


void morrisInorderTraversal(Node* head){

  Node* current = head;
  if(current==NULL){return;}

  while(current!=NULL){

    if(current->left==NULL){
      std::cout << current->data <<" ";
      current=current->right;

    }else{

      Node* predecessor = findPred(current);

      if(predecessor->right==NULL){
        predecessor->right=current;
        current=current->left;
      } else{
        predecessor->right=NULL;
        std::cout << current->data <<" ";
        current=current->right;
      }

    }
  }
}


int main(){

  Node * head=NULL;
  head=Insert(9,head);
  head=Insert(2,head);
  head=Insert(8,head);
  head=Insert(6,head);
  head=Insert(7,head);
  head=Insert(5,head);
  head=Insert(1,head);
  morrisInorderTraversal(head);
std::cout << std::endl;
}
