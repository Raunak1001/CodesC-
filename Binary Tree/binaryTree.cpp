#include<iostream>
#include<queue>
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

void printInorder(Node* head){
  Node *temphead=head;
if(head==NULL){
  return;
}
printInorder(temphead->left);
  cout<<head->data<<" ";

printInorder(temphead->right);

}

void preOrder(Node* head) {
  Node *temphead=head;

  if(temphead==NULL){
return;
  }
std::cout << head->data <<" ";
preOrder(temphead->left);
preOrder(temphead->right);


}

void postOrder(Node* head){
  Node *temphead=head;

  if(temphead==NULL){
return;
  }
postOrder(temphead->left);
postOrder(temphead->right);
std::cout << temphead->data << " ";

}

void levelOrder(Node* node){

queue<Node*> q;
Node* n= getNewNode(1000);

if(node==NULL){
  return;
}
q.push(n);

while(true){

if(node==n && !q.empty()){

q.push(n);
std::cout <<endl;
  node=q.front();
  q.pop();

}
if(node==n && q.empty()){
  break;
}
std::cout << node->data <<" ";

if(node->left !=NULL )
  q.push(node->left);
if(node->right !=NULL)
q.push(node->right);

if(!q.empty()){
node=q.front();
q.pop();
}
else break;
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
printInorder(head);
std::cout <<endl;
preOrder(head);
std::cout <<endl;
postOrder(head);
std::cout <<endl;
levelOrder(head);
std::cout <<endl;

}
