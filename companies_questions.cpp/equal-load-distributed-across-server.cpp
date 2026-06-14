#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &tasks,int k,int mid){
  int server = 1; //all server must have one load no idle
  int currload=0;

  for(int i=0;i<tasks.size();i++){
        if(currload+tasks[i]>mid){
          server++;
          currload = tasks[i];
        }
        else{
          currload += tasks[i];
        }
  }

  return server <= k;
}

int solve(vector<int> &tasks,int k){
      int start=*max_element(tasks.begin(),tasks.end());
      int end=accumulate(tasks.begin(),tasks.end(),0);

      int ans=-1;
      while(start<=end){
        int mid = start + (end - start) / 2;
        if(isPossible(tasks,k,mid)){
          ans = mid;
          end = mid - 1;
        }
        else{
          start = mid + 1;
        }
      }
 return ans;
}

int main(){
  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    vector<int> tasks(n,0);
    
    for(int i=0;i<n;i++){
      cin >> tasks[i];
    }
    
    int k;
    cin>>k;

    cout<< solve(tasks, k) << endl;
  }
  return 0;
}