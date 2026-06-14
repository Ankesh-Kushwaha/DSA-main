// there is give a number a and b. your task is to count the number of integers between a and b where no two adjacent digits are the same;
// contraints 0<= a <= b<= 10^18;
// hints to recognise it is a digit dp problem
// 1. given with a range [a,b]
// contarints are too high
// we have to perform some operations and count the total numbers;


#include<bits/stdc++.h>
using namespace std;

long long dp[19][11][2][2];
long long solve_helper(string &s,long long idx,long long prev,bool tight,bool lz){
  if(idx==s.length())
    return 1;
  
  if(dp[idx][prev][tight][lz] !=-1)
    return dp[idx][prev][tight][lz];
  
  long long lb = 0;
  long long ub = (tight == 1) ? s[idx] - '0' : 9;

  long long ans = 0;
  for (long long d = lb; d <= ub;d++){
       if(prev==d && !lz) //if break the condition and there is no any leading zero skip
         continue;
       bool new_tight = (tight && d == ub);
       ans += solve_helper(s, idx + 1, d,new_tight, (lz && d == 0));
  }
  return dp[idx][prev][tight][lz]=ans;
} 

long long solve(long long a , long long b){
  // what we do is count the diff of  total(b)-total(a-1); this gives us total in range [a,b];
  string l = to_string(a - 1);
  string r = to_string(b);
  // string , idx, prev, tight, lz=> leading zeroes;
  memset(dp,-1, sizeof(dp));
  long long ans_l=solve_helper(l,0,10,1,1);
  memset(dp,-1, sizeof(dp));
  long long ans_r = solve_helper(r, 0, 10, 1, 1);
  return ans_r - ans_l;
}

int main(){
  long long a, b;
  cin>>a>>b;

  cout << solve(a, b) << endl;
  return 0;
}
