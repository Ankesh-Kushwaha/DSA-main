#include<bits/stdc++.h>
using namespace std;

class LRU_Cache
{
  list<int> dll; // front = MRU, back = LRU

  // key -> {iterator in list, value}
  unordered_map<int, pair<list<int>::iterator, int>> cache;

  int capacity;

public:
  LRU_Cache(int capacity)
  {
    this->capacity = capacity;
  }

  void makeRecentlyUsed(int key)
  {
    dll.erase(cache[key].first);

    dll.push_front(key);

    cache[key].first = dll.begin();
  }

  int get(int key)
  {
    if (cache.find(key) == cache.end())
      return -1;

    makeRecentlyUsed(key);

    return cache[key].second;
  }

  void put(int key, int value)
  {

    // Key already exists
    if (cache.find(key) != cache.end())
    {
      cache[key].second = value;
      makeRecentlyUsed(key);
      return;
    }

    // Insert new key
    dll.push_front(key);
    cache[key] = {dll.begin(), value};

    // Evict LRU if capacity exceeded
    if (cache.size() > capacity)
    {
      int lruKey = dll.back();

      dll.pop_back();

      cache.erase(lruKey);
    }
  }

  void display()
  {
    cout << "Cache State (MRU -> LRU): ";

    for (auto key : dll)
    {
      cout << "(" << key << "," << cache[key].second << ") ";
    }

    cout << '\n';
  }
};

int main(){
  LRU_Cache cache(2);

  // cache.put(1, 1);
  // cache.put(2,2);
  // cout<<cache.get(1)<<endl;
  // cache.put(3,3);
  // cout<<cache.get(2)<<endl;
  // cache.put(4,4);
  // cout<<cache.get(1)<<endl;
  // cout<<cache.get(3)<<endl;
  // cout << cache.get(4) << endl;

  int t;
  cin >> t;
  cin.ignore(); //ignore the newline

  //take input 
  while(t--){
    string line;
    getline(cin, line);

    //convert it into the stream
    stringstream ss(line);
    string ops;
    ss >> ops;

    if(ops=="get"){
      string val;
      ss >> val;
      cout<<cache.get(stoi(val))<<endl;
    }
    else{
      string key, val;
      ss >> key;
      ss >> val;

      cache.put(stoi(key), stoi(val));
    }
  }
  return 0;
}