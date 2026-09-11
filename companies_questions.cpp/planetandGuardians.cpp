#include<bits/stdc++.h>
using namespace std;

void bfs(int src,int d,unordered_map<int,vector<int>> &graph,vector<int> &vis,vector<int> &ans){
  queue<pair<int, int>> q;
  q.push({0,src});
  vis[src] = 1;

  while(!q.empty()){
    int sz = q.size();
    while(sz--){
      int dst = q.front().first;
      int u = q.front().second;
      q.pop();

      
      ans.push_back(u);

      for(auto &v:graph[u]){
            if(dst+1>d)
              continue;
            if(!vis[v]){
              q.push({dst + 1, v});
              vis[v] = 1;
            }
      }
    }
  }

}

int main(){
  int N, M, K;
  cin >> N >> M >> K;
  unordered_map<int,vector<int>> graph;
  for (int i = 0; i < M;i++){
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  vector<pair<int,int>> guardians;
  for (int i = 0; i < K;i++){
    int x, d;
    cin >> x >> d;
    guardians.push_back({x, d});
  }

  vector<int> ans;
  vector<int> vis(N, 0);
  queue<pair<int, int>> q;
  for (int i = 0; i < K;i++){
     if(!vis[guardians[i].first]){
       bfs(guardians[i].first, guardians[i].second, graph, vis, ans);
     }
  }

  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size();i++){
    cout << ans[i] << " ";
  }
    return 0;
}