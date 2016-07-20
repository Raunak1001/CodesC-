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


bool checkSum(Node* head){
  Node* node=head;
  if(head==NULL){return true;}

  if(node->left!= NULL && node->right!=NULL){
    if(node->data != node->left->data + node->right->data){
      return false;
    }
  }else{
    if(node->left !=NULL){
      if(node->data!= node->left->data){return false;}

    }else if(node->right !=NULL)
    if(node->data != node->right->data){return false;}

  }

  if(checkSum(node->left) && checkSum(node->right)){
    return true;}
  else
  return false;



}

int main(){


  Node *root  = getNewNode(10);
  root->left         = getNewNode(8);
  root->right        = getNewNode(2);
  root->left->left   = getNewNode(3);
  root->left->right  = getNewNode(5);
  root->right->right = getNewNode(2);

  if(checkSum(root)){
    std::cout << "Yes" << std::endl;
  }else
  std::cout << "No" << std::endl;

}
