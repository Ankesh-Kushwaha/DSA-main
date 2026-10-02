#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<string> meters;
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    meters.push_back(s);
  }

  int central = 0;
  cin >> central;

  unordered_map<char, int> mp;
  mp['A'] = 0;
  mp['B'] = 1;
  mp['C'] = 2;
  mp['D'] = 3;
  mp['E'] = 4;
  mp['F'] = 5;
  mp['G'] = 6;
  mp['H'] = 7;
  mp['I'] = 8;
  mp['J'] = 9;

  long long ans = 0;

  for (auto m:meters){

    int temp = 0;
    for (int i = 0; i < m.length();i++){
        if(i+1<m.length() && m[i]=='J' && m[i+1]=='A'){
          int val = mp['A'];
          temp = temp * 10 + val;
        }
        else if (i+1 < m.length() && m[i] == 'I' && m[i + 1] == 'B'){
          int val = mp['B'];
          temp = temp * 10 + val;
        }
        else if (i + 1 < m.length() && m[i] == 'H' && m[i + 1] == 'C')
        {
          int val = mp['C'];
          temp = temp * 10 + val;
        }
        else if (i + 1 < m.length() && m[i] == 'G' && m[i + 1] == 'D')
        {
          int val = mp['D'];
          temp = temp * 10 + val;
        }
        else if (i + 1 < m.length() && m[i] == 'F' && m[i + 1] == 'E')
        {
          int val = mp['E'];
          temp = temp * 10 + val;
        }
        else{
          int val = mp[m[i]];
          temp = temp * 10 + val;
        }
    }
    ans += temp;
  }

  if(ans<=central){
    cout << "INNOCENT" << endl;
  }
  else{
    cout << "GREEDY" << endl;
    cout << ans - central << endl;
  }
    return 0;
}