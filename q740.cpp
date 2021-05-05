#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int> &nums)
    {
        int size = nums.size();
        int first = nums[0] , second = max(nums[1], nums[0]);
        for(int i = 2; i < size; i++)
        {
            int temp = second;
            second = max(second, nums[i] + first);
            first = temp;
        }
        return second;

    }
    
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = 0;
        for(int num : nums)
        {
            maxVal = max(maxVal, num);
        }
        vector<int> sum(maxVal + 1);    //初始化后默认为0
        for(int num : nums)
        {
            sum[num] += num;
        }
        return rob(sum);


    }
};