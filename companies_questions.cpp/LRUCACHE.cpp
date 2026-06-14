#include<bits/stdc++.h>
using namespace std;


class LRU_Cache{
  list<int> dll;//store front as most recently used key
  // cahce store the value and address of each node for O(1) lookup;
  unordered_map<int, pair<list<int>::iterator, int>> cache;
  int capapcity;


public:
  LRU_Cache(int capacity){
    this->capapcity = capacity;
  }
  
  void makeRecentlyUsed(int key){
     //first erase it from the list
     dll.erase(cache[key].first);
     //now push it in the front to mark it recently used
     dll.push_front(key);
     // now update the address of the key into the cahce;
     cache[key].first = dll.begin();
  }

  // get the key from the  cache and its value;
  int get(int key){
      if(cache.find(key)==cache.end()) return -1;
      // get the key and return its values from the map;
      int val=cache[key].second;
      //since this is recently used put it to the front
      makeRecentlyUsed(key);
      return val;
  }

  void put(int key,int value){
      //if the key is present then update it and make it recently used 
      if(cache.find(key)!=cache.end()){
         //update the value;
          cache[key].second=value;
          //mark it recently used
          makeRecentlyUsed(key);
      }
      else{
        //push it in the front 
        dll.push_front(key);
        // store its address and value in the cache;
        cache[key] = {dll.begin(), value};
        capapcity--;
      }
      
      if(capapcity<0){ //remove the most recently used element
        int key_to_be_deleted = dll.back();
        dll.pop_back();
        cache.erase(key_to_be_deleted);
      }
      
  }
};

int main(){
  LRU_Cache cache(2);

  cache.put(1, 1);
  cache.put(2,2);
  cout<<cache.get(1)<<endl;
  cache.put(3,3);
  cout<<cache.get(2)<<endl;
  cache.put(4,4);
  cout<<cache.get(1)<<endl;
  cout<<cache.get(3)<<endl;
  cout << cache.get(4) << endl;
  return 0;
}