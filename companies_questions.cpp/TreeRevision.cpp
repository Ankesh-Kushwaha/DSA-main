#include<bits/stdc++.h>
using namespace std;

class Node{
 public:
   int val;
   Node *left;
   Node *right;

   Node(int val){
     this->val = val;
     left = right = NULL;
   }
};


class Tree{
    public:
   
    Node* buildFromPreOrder( vector<int> &nums,int idx){

    }

    Node* buildLevelOrder(vector<int> &nums){
      int idx = 0;
      int n = nums.size();
      queue<Node*> q;

      Node *newNode = new Node(nums[idx]);
      q.push(newNode);
      idx++;

      while(!q.empty()){
        Node *curr = q.front();
        q.pop();

        if(idx<n){
          curr->left = new Node(nums[idx]);
          if(curr->left!=NULL)
            q.push(curr->left);
          idx++;
        }       
        
        if(idx<n){
          curr->right = new Node(nums[idx]);
          if(curr->right!=NULL)
            q.push(curr->right);
          idx++;
        }
      }

      return newNode;
    }

    void preOrder(Node*  root){
       if(root==NULL)
         return;

       cout << root->val << " ";
       preOrder(root->left);
       preOrder(root->right);
    }

   void postOrder(){

    }

    void levelOrder(){

    }

   int findPathSum(Node* root){

   }

   int findHeight(Node* root){

   }

   int findDiameter(Node* root){

   }
};

int main(){
  string str;
  getline(cin, str);
  stringstream ss(str);
  //cout << str;

  vector<int> nums;
  for(char ch:str){
       if(ch==' ')
         continue;
      if(isdigit(ch)){
        nums.push_back(ch - '0');
      }
  }

  Tree *tree = new Tree();
  Node *root = tree->buildLevelOrder(nums);
  tree->preOrder(root);
  return 0;
}