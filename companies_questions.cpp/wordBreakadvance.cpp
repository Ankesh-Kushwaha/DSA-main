#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j,string &str1,string &str2,vector<vector<int>> &dp){
    if(i>=str1.length())
      return  str2.length()-j;
    if(j>=str2.length())
      return str1.length()-i;
    
    if(dp[i][j]!=-1)
      return dp[i][j];
    if(str1[i]==str2[j])
      return dp[i][j]=solve(i + 1, j + 1, str1, str2,dp);
    else{
      return dp[i][j]=1 + min({solve(i + 1, j + 1, str1, str2,dp),
                      solve(i + 1, j, str1, str2,dp),
                      solve(i, j + 1, str1, str2,dp)});
    }
}

int main(){
  string str1;
  string str2;

  getline(cin, str1);
  getline(cin, str2);

  vector<string> arr;
  string word = "";

  for (int i = 0; i < str1.length();i++){
        if(str1[i]==','){
          arr.push_back(word);
          word = "";
          continue;
        }

        word += str1[i];
  }

  arr.push_back(word);

  int mini = INT_MAX;
  string ans = "";

  for(auto s:arr){
    vector<vector<int>> dp(s.length(), vector<int>(str2.length(), -1));
    int temp = solve(0, 0, s, str2,dp);
    if(temp<mini){
      mini = temp;
      ans = s;
    }
  }

  cout << ans << endl;
  return 0;
}