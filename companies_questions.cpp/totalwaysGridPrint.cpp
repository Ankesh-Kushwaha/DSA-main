#include<bits/stdc++.h>
using namespace std;

int m, n = 0;
void solve(int i,int j,vector<vector<int>> &grid,string &temp,vector<string> &ans,vector<vector<int>> &vis){
      if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==1 || vis[i][j])
        return;
      
      if(i==m-1 && j==n-1){
        ans.push_back(temp);
      }

      vis[i][j] = 1;

      if(j+1<n && grid[i][j+1]!=1){
        temp.push_back('R');
        solve(i, j + 1, grid, temp, ans,vis);
        temp.pop_back();
      }

      if(i+1<m && grid[i+1][j]!=1){
        temp.push_back('D');
        solve(i + 1, j, grid, temp, ans,vis);
        temp.pop_back();
      }

      if(j-1>=0 && grid[i][j-1]!=1){
        temp.push_back('L');
        solve(i, j - 1, grid, temp, ans,vis);
        temp.pop_back();
      }

      if(i-1>=0 && grid[i-1][j]!=1){
        temp.push_back('U');
        solve(i - 1, j, grid, temp, ans,vis);
        temp.pop_back();
      }

      vis[i][j] = 0;
}

int main(){
  cin >> m >> n;

  vector<vector<int>> grid(m, vector<int>(n, 0));
  for (int i = 0; i < m;i++){
    for (int j = 0; j < n;j++){
      cin >> grid[i][j];
    }
  }

  string temp;
  vector<string> ans;
  vector<vector<int>> vis(m, vector<int>(n, 0));
  solve(0,0,grid,temp,ans,vis);

  for(auto str:ans){
    cout << str << endl;
  }
  return 0;
}