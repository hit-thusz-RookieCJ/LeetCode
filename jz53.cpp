#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return upper_bound(begin(nums), end(nums), target) - lower_bound(begin(nums), end(nums), target);
    }
};