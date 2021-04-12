#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val) == map.end()){
            map[val] = vec.size();
            vec.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val) != map.end()){
            int pos = map[val];
            map.erase(val);

            // 操作数组
            if(vec[pos] == vec[vec.size() - 1]){
                vec.pop_back();
                return true;
            }
            swap(vec[pos], vec[vec.size() - 1]);
            vec.pop_back();
            map[vec[pos]] = pos;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand() % vec.size()];
    }

private:
    unordered_map<int, int> map;
    vector<int> vec;
};
