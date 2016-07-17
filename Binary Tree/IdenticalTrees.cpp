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

bool IsIdentical(Node* head1, Node* head2){

  if(head1!=NULL && head2!=NULL)
  {
    if(head1->data !=head2->data)
    {
      return false;
    }
  }

  if(head1== NULL && head2 == NULL){
    return true;
  }
  else if(head1 == NULL){
    return false;}

    else if(head2== NULL)
    {
      return false;}

      if(IsIdentical(head1->left,head2->left) && IsIdentical(head1->right , head2->right))
      return true;
      return false;

    }



    int main(){

      Node * head1=NULL;
      Node * head2=NULL;


      head1=Insert(9,head1);
      head1=Insert(2,head1);
      head1=Insert(8,head1);
      head1=Insert(6,head1);
      head1=Insert(7,head1);
      head1=Insert(5,head1);
      head1=Insert(1,head1);

      head2=Insert(9,head2);
      head2=Insert(2,head2);
      head2=Insert(8,head2);
      head2=Insert(6,head2);
      head2=Insert(7,head2);
      head2=Insert(5,head2);
      head2=Insert(1,head2);

      if(IsIdentical(head1,head2))
      std::cout << "Identical" << std::endl;
      else
      std::cout <<"Not Identical"<< std::endl;
    }
