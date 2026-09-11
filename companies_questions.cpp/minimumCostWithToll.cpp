#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
int dijkstra( int X, int Y,int K, unordered_map<int, vector<pair<int, int>>> &graph, unordered_map<int, int> &tolls){
  priority_queue<P, vector<P>, greater<P>> pq;

  vector<int> dist(graph.size(), INT_MAX);

  dist[X] = 0;
  pq.push({0, X});

  while (!pq.empty())
  {
    auto curr = pq.top();
    int cost = curr.first;
    int node = curr.second;
    pq.pop();

    if (cost > dist[node])
      continue;

    // Never visit K
    if (node == K)
      continue;

    // We reached destination
    if (node == Y)
      return cost;

    for (auto &ngb : graph[node]){
      int next = ngb.first;
      int edgeWeight = ngb.second;

      // Don't visit K
      if (next == K)
        continue;

      int newCost = cost + edgeWeight;

      // Add toll of next node, if it exists
      if (tolls.count(next))
      {
        newCost += tolls[next];
      }

      if (newCost < dist[next])
      {
        dist[next] = newCost;
        pq.push({newCost, next});
      }
    }
  }

  return -1;
}

int main()
{
  int N, E;
  cin >> N >> E;

  unordered_map<int, vector<pair<int, int>>> graph;
  // Edges
  for (int i = 0; i < E; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;

    graph[u].push_back({v, wt});
    graph[v].push_back({u, wt});
  }

  // Tolls
  int T;
  cin >> T;

  unordered_map<int, int> tolls;

  for (int i = 0; i < T; i++)
  {
    int node, tollWt;
    cin >> node >> tollWt;

    tolls[node] = tollWt;
  }

  int X, Y, K;
  cin >> X >> Y >> K;

  cout << dijkstra(X, Y, K, graph, tolls) << endl;

  return 0;
}