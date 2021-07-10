#include <bits/stdc++.h>
using namespace std;
#include <UTILITY>

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> m;
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto &pairs = m[key];
        // 使用一个大于所有 value 的字符串，以确保在 pairs 中含有 timestamp 的情况下也返回大于 timestamp 的位置(127，ASCII码最大值)
        pair<int, string> p = {timestamp, string({127})};
        auto i = upper_bound(pairs.begin(), pairs.end(), p);
        if (i != pairs.begin()) {
            return (i - 1)->second;
        }
        return "";
    }
};

// int main()
// {
//     string a = string({127});
//     string b = string("abcddea");
//     if(a > b)
//     {
//         cout << 1;
//     }
//     cout << a;
//     cin.get();
//     return 0;
// }