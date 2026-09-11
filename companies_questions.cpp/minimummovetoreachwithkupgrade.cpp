#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int solve(vector<vector<int>> &grid,int k){
  int m = grid.size();
  int n = grid[0].size();
  vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int>(k + 1, 0)));
  queue<tuple<int, int, int, int>> q;
  q.push({0, 0, 0, k});
  vis[0][0][k] = 1;

  while(!q.empty()){
    auto [steps, x, y, rem_k] = q.front();
    q.pop();

    if(x==m-1 && y==n-1)
      return steps;
    
    for(auto d:dir){
      int x_ = x + d[0];
      int y_ = y + d[1];

      if((x_>=0 && x_<m) && (y_>=0 && y_<n)){
        int new_k = rem_k - grid[x_][y_];

        if(new_k>=0 && !vis[x_][y_][new_k]){
          vis[x_][y_][new_k] = 1;
          q.push({steps + 1, x_, y_, new_k});
        }
      }
    }
  }

  return -1;
}

int main(){
  int m, n;
  cin >>m>>n;
  vector<vector<int>> arr(m, vector<int>(n, 0));
  for (int i = 0; i < m;i++){
    for (int j = 0; j < n;j++){
      cin >> arr[i][j];
    }
  }

  int k;
  cin >> k;

  cout << solve(arr,k)<< endl;
  return 0;
}