#include<bits/stdc++.h>
using namespace std;

void dfs(int src,vector<int> &Nodes,vector<int> &vis,vector<int> &pos,vector<int> &path,int &ans){
  vis[src] = 1;
  pos[src] = path.size(); // store the current pos of node in that cycle;
  path.push_back(src); //store for further calculation

  int nextNode = Nodes[src];
  if(nextNode!=-1){
       if(!vis[nextNode]){
         dfs(nextNode, Nodes, vis, pos, path,ans);
       }
       else
       { // that means it is already in the cycle and we find a cycle;
         int sum = 0;
         for (int i = pos[nextNode]; i < path.size();i++){
           sum += path[i];
         }

         ans = max(ans, sum);
       }
  }

  vis[src] = 2;//remove from the graph because it is processed
  path.pop_back();
  pos[src] = -1;
}

int main(){
  int N;
  cin >> N;
  vector<int> Nodes(N, 0);

  for (int i = 0; i < N;i++)
    cin >> Nodes[i];

  vector<int> vis(N, 0);
  vector<int> pos(N, -1);
  vector<int> path;

  int ans = -1;
  for (int i = 0; i < N;i++){
      if(!vis[i]){
        dfs(i, Nodes, vis, pos, path,ans);
      }
  }

  cout << ans << endl;

  return 0;
}

/*
Problem : 2 Largest Sum Cycle (Medium-Hard)
The task is to find the largest sum of a cycle in the maze(Sum of a cycle is the sum of the cell indexes of all cells present in that cycle).
Note:The cells are named with an integer value from 0 to N-1. If there is no cycle in the graph then return -1.

Example 1:

Input:
23
4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21

Output:
45
*/