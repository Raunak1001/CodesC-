#include<iostream>
#include<queue>
#include<stack>

using namespace std;


struct Node{
  int data;
  Node* left;
  Node* right;
};
Node* NewNode(int data){

  Node* n= new Node();
  n->data=data;
  n->left=NULL;
  n->right=NULL;
  return n;
}

Node* insert(int data, Node * head){



  Node* n =NewNode(data);
  Node* temphead=head;
  Node* prev;

  if(head== NULL){
    head=n;
    return head;;

  }

  while(temphead!=NULL){
    prev=temphead;
    if(temphead->data < data){
      temphead=temphead->right;

    }
    else{
      temphead=temphead->left;
    }

  }

  if(prev->data<data){
    prev->right=n;
  }else{
    prev->left=n;
  }

  return head;
}


void preOrder(Node* node){
  std::cout << node->data << " ";
  if(node->left!=NULL){
    preOrder(node->left);
  }
  if(node->right!=NULL){
    preOrder(node->right);
  }

}

void postOrder(Node* node){
  if(node==NULL){
    return;
  }

  postOrder(node->left);

  postOrder(node->right);
  std::cout << node->data << " ";
}

void Inorder(Node* head){
  if(head==NULL){
    return;
  }

  Inorder(head->left);
  std::cout << head->data << " ";
  Inorder(head->right);

}

void LevelOrder(Node* head){

  queue<Node*> q;
  q.push(head);
  while(!q.empty()){
    Node* temp=q.front();
    q.pop();

    std::cout << temp->data << " ";
    if(temp->left!=NULL){
      q.push(temp->left);

    }
    if(temp->right!=NULL){
      q.push(temp->right);
    }

  }


}

bool isLeaf(Node* head){
  if(head->left==NULL && head->right == NULL){
    return true;
  }else{
    return false;
  }

}

bool RootToLeaf(Node* head, int sum){


  if(sum<0){
    return false;
  }
  if(head->data==sum){
    if(isLeaf(head)){
      std::cout << head->data <<" ";
      return true;}
      else{
        return false;
      }
    }

    if(head->left!=NULL){
      if(RootToLeaf(head->left,sum-head->data)){
        std::cout << head->data <<" ";
        return true;
      }
    }
    if(head->right!=NULL){
      if(RootToLeaf(head->right,sum-head->data)){
        std::cout << head->data <<" ";
        return true;
      }
    }
    return false;

  }


  int size(Node * head){


    if(head==NULL){
      return 0;
    }
    int leftHeght=size(head->left);
    int rightHeight=size(head->right);
    return leftHeght+rightHeight+1;


  }


  int Height(Node* head){

    if(head==NULL){
      return 0;
    }

    int leftHeght=Height(head->left);
    int rightHeight=Height(head->right);
    return max(leftHeght,rightHeight)+1;

  }

  void printLevelNode(Node* head, int level,int temp,stack<int> &s){
    if(head==NULL){
      return;
    }
    if(level==1){
      if(temp==0){
        cout << head->data << " ";
      }else{
        s.push(head->data);

      }
    }else{
      printLevelNode(head->left,level-1,temp,s);
      printLevelNode(head->right,level-1,temp,s);

    }
  }

  void PrintLevelOrder(Node* head){
    stack<int> s;
    int height=Height(head);
    for(int i=1; i<=height;i++){
      printLevelNode(head,i,i%2,s);

      while(!s.empty())
      {
        std::cout << s.top() << " ";
        s.pop();
      }
      cout << endl;
    }
  }

  bool Ancestor(Node* head, int a,int b){
    if(head==NULL){
      return false;
    }


    bool i=Ancestor(head->left,a,b);

    bool j= Ancestor(head->right,a,b);
    if( i && j){
      cout << head->data <<endl;
      return false;
    }else if(i){
      return i;
    }else{
      return j;
    }



  }


  int main(){

    Node* head= NULL;

    head=insert(10,head);
    insert(1,head);
    insert(9,head);
    insert(8,head);
    insert(6,head);
    insert(2,head);
    insert(7,head);
    insert(3,head);
    insert(8,head);
    preOrder(head);
    std::cout << std::endl;
    postOrder(head);
    std::cout << std::endl;
    Inorder(head);
    std::cout << std::endl;
    LevelOrder(head);
    std::cout  << std::endl;
    std::cout << size(head) << std::endl;
    std::cout << Height(head) << std::endl;

    if(!RootToLeaf(head,49)){
      std::cout << "sum does not exisit" << std::endl;
    }else{
      std::cout <<std::endl;
    }

    PrintLevelOrder(head);

    Ancestor(head,3,7);

  }
