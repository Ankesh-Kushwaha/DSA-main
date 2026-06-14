#include<bits/stdc++.h>
using namespace std;

class segmentTree{
  vector<int> tree;
  public:
  segmentTree(int n,vector<int> &arr){
    tree.resize(4 * n);
    buildTree(arr, 0, n - 1, 0);
  }

  void buildTree(vector<int> &arr,int left,int right,int node){
     if(left==right){
       tree[node] = arr[left];
       return;
     }

     int mid=(left+right)/2;
     buildTree(arr, left, mid, 2 * node + 1);
     buildTree(arr, mid + 1, right, 2 * node + 2);
     tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
  }
  
  int queryHelper(int q1,int q2,int left,int right,int node){

  }
  
  int query(int q1,int q2){
    return queryHelper(q1, q2, 0, n - 1, 0);
  }
};
int main(){

  return 0;
}