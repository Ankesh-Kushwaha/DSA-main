#include<bits/stdc++.h>
using namespace std;

int Power(int a,int b){
  if(b==0)
    return 1;
  
  int half=Power(a,b/2);
  if(b%2!=0)
    return a * half * half;
  else
    return half * half;
}

int main(){
  int a,b;
  cin>>a>>b;
  cout << Power(a, b) << endl;
  return 0;
}