/*Problem : 1 Maximum Weight Node (Easy)
The task is to find the cell with maximum weight (The weight of a cell is the sum of cell indexes of all cells pointing to that cell). If there are multiple cells with the maximum weight return the cell with highest index.
Note: The cells are indexed with an integer value from 0 to N-1. If there is no cell pointing to the ith cell then the weight of the i'th cell is zero.

INPUT FORMAT :

The first line contains the number of cells N.
The second line has a list of N values of the edge[ ] array, where edge[i] conatins the cell number that can be reached from cell 'i' in one step. edge[i] is -1 if the ith doesn't have ans exit.*/

#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> Nodes(N, 0);

  for (int i = 0; i < N;i++){
    cin >> Nodes[i];
  }

  vector<int> cnt(N, 0);
  for (int i = 0; i < N;i++){
     if(Nodes[i]!=-1){
       cnt[Nodes[i]] += i;
     }
  }

  int Maxi = INT_MIN;
  int ans = -1;
  for (int i = 0; i < N;i++){
     if(Maxi<=cnt[i]){
       Maxi = cnt[i];
       ans = i;
     }
  }

  cout << ans << endl;

  return 0;
}