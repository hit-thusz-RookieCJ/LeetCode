#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for(int &num : nums)
        {
            if(count == 0)
            {
                candidate = num;
            }
            if(candidate != num)
            {
                count--;
            }
            else{
                count++;
            }
        }
        count = 0;
        for(int &num : nums)
        {
            if(num == candidate)
            {
                count++;
            }
        }
        return count*2 > nums.size() ? candidate : -1;
    }
};