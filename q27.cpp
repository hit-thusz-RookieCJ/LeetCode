#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); )
        {
            if(*it == val)
            {
                it = nums.erase(it); // 返回删除元素的下一个位置
            }
            else
            {
                it++;
            }
        }
        return nums.size();
    }
};