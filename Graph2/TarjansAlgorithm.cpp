#include<bits/stdc++.h>
using namespace std;

static int timer = 1;
void dfs(int src,int par,unordered_map<int,vector<int>> &graph,vector<int> &tin,vector<int> &low,vector<int> &vis ,vector<vector<int>>  &bridges){
  vis[src] = 1;
  tin[src] = timer;
  low[src] = timer;
  timer++;

  for(auto v:graph[src]){
     if(v==par)
       continue;
    
    if(vis[v]==0){
      dfs(v, src, graph, tin, low, vis, bridges);

      low[src] = min(low[src], low[v]);
      if(low[v]>tin[src]){
        bridges.push_back({src, v});
      }
    }
    else{
      low[src] = min(low[src], low[v]);
    }
  }
}

int main(){
  int n;
  cin >> n;
  vector<vector<int>> edges;

  for (int i = 0; i < n;i++){
    int u, v;
    cin >> u >> v;

    edges.push_back({u, v});
  }

  unordered_map<int, vector<int>> graph;
  for(auto e:edges){
     graph[e[0]].push_back(e[1]);
     graph[e[1]].push_back(e[0]);
  }

  vector<int> tin(n);
  vector<int> low(n);
  vector<int> vis(n);
  vector<vector<int>> bridges;
  dfs(0, -1, graph, tin, low, vis, bridges);

  for (int i = 0; i < bridges.size();i++){
    for (int j = 0; j < 2;j++){
      cout << bridges[i][j] << " ";
    }
    cout << endl;
  }

    return 0;
}