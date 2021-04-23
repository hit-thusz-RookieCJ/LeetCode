#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        int maxnum = 1, maxvalue = nums[0];

        vector<int> dp(len, 1);
        for(int i = 1; i < len; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(nums[i] % nums[j] == 0)
                {
                    dp[i] = max(dp[i], dp[j] + 1);

                }
            }
            if(dp[i] > maxnum)
            {
                maxnum = dp[i];
                maxvalue = nums[i];
            }
        }

        vector<int> ans;
        if(maxnum == 1)
        {
            ans.push_back(nums[0]);
            return ans;
        }

        for(int i = len - 1; i >= 0 && maxnum > 0; i--)
        {
            if(maxvalue % nums[i] == 0 && dp[i] == maxnum)
            {
                ans.push_back(nums[i]);
                maxnum--;
                maxvalue = nums[i];
            }
        }
        return ans;

    }
};