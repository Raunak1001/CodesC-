#include<iostream>
#include<queue>

using namespace std;

struct Node{

  int data;
  Node* left;
  Node* right;
};

Node* getNewNode(int data){
  Node* n= new Node();
  n->data=data;
  n->left=NULL;
  n->right=NULL;
  return n;

}


void increment(Node* node, int diff){

  if(node->left != NULL){
    node->right->data=node->right->data+diff;
    increment(node->right,diff);
  }else if(node->left != NULL){
    node->left->data=node->right->data+diff;
    increment(node->left,diff);
  }
}

void convert(Node* node){

  if(node==NULL){
    return;}

    convert(node->left);
    convert(node->right);

    if(node->left != NULL && node->right!= NULL){
      int diff=node->data-(node->left->data+node->right->data);

      if(diff!=0){

        if(diff>0){
          increment(node,diff);
        }else{
          node->data=node->data-diff;
        }
      }
    }
    else if(node->left != NULL){
      int diff=node->data-node->left->data;


      if(diff>0){
        increment(node,diff);
      }else{    node->data=node->left->data;
      }

    }else if(node->right != NULL){

      int diff=node->data-node->right->data;


      if(diff>0){
        increment(node,diff);
      }else{    node->data=node->right->data;
      }
    }

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

    Node *root = getNewNode(50);
    root->left        = getNewNode(7);
    root->right       = getNewNode(2);
    root->left->left  = getNewNode(3);
    root->left->right = getNewNode(5);
    root->right->left  = getNewNode(1);
    root->right->right = getNewNode(30);

    levelOrder(root);
    std::cout <<endl;

    convert(root);

    levelOrder(root);
    std::cout<<endl;


  }
