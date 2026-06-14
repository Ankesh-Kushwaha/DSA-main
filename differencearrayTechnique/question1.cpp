#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums,vector<vector<int>> &queries){
  int n = nums.size();
  vector<int> diff(n, 0);

  for(auto q:queries){
    int l = q[0];
    int r = q[1];
    int x = q[2];

    if(l>=0)
      nums[l] += x;
    
    if(r+1<n) nums[r+1]-=x;
  }

  // find cummulative sum;
  for (int i = 1; i < n; i++)
  {
    diff[i] += diff[i - 1];
  }

  return diff;
}

int main(){
  int n,Q;
  cin >> n >> Q;

  vector<int> nums(n);
  for (int i = 0; i < n;i++){
    cin >> nums[i];
  }

  vector<vector<int>> queries;
  for (int i = 0; i < Q;i++){
    int l, r, x;
    cin >> l >> r >> x;
    queries.push_back({l, r, x});
  }

  vector<int> ans = solve(nums, queries);
  for (int i = 0; i < ans.size();i++){
    cout << ans[i] << " ";
  }

    return 0;
}