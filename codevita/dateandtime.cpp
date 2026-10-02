#include<bits/stdc++.h>
using namespace std;

bool isPresent(unordered_map<char,int> &mp,int i){
  string str = to_string(i);
  if(str.length()==1)
    str = "0" + str;

  if(mp[str[0]]<=0 || mp[str[1]]<=0)
    return false;
  else{
    mp[str[0]]--;
    mp[str[1]]--;
  }

  return true;
}

int main(){
  string s;
  cin >> s;

  unordered_map<char, int> mp;
  for (int i = 0;i<s.length();i++)
  {
    mp[s[i]]++;
  }

    string month = "";

  //building largest month
  for (int i = 12; i >= 1;i--){
       if(isPresent(mp,i)){
         month = to_string(i);
         break;
       }
  }
  
  if(month.length()==1)
    month = "0" + month;

  // build date;
  string date = "";
  for (int i = 31; i >= 1;i--){
      if(month=="2" && i>28)
        continue;
      else if(month=="2" && i<=28){
        if (isPresent(mp,i)){
          date = to_string(i);
          break;
        }
      }
      else if((month=="4" || month=="6" || month=="9" || month=="11") && i<31 ){
         if(isPresent(mp,i)){
           date = to_string(i);
           break;
         }
      }
      else{
         if(isPresent(mp,i)){
           date = to_string(i);
           break;
         }
      }
  }
   
  if(date.length()==1)
    date = "0" + date;
  
  //build hours
  string hour = "";
  for (int i = 23; i >= 0;i--){
     if(isPresent(mp,i)){
       hour = to_string(i);
       break;
     }
  }

  if(hour.length()==1)
    hour = "0" + hour;

  //building minutes
  string minutes = "";
  for (int i = 59; i >= 0;i--){
     if(isPresent(mp,i)){
       minutes = to_string(i);
       break;
     }
  }
  
  if(minutes.length()==1)
    minutes = "0" + minutes;

  if(month.empty() || date.empty() || hour.empty() || minutes.empty()){
    cout << 0 << endl;
  }
  else{
    cout << month << "/" << date << " " << hour << ":" << minutes << endl;
  }
    return 0;
}