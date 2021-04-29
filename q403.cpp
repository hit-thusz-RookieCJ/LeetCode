#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        dp[0][0] = true;
        for(int i = 1; i < n; i++)
        {
            if(stones[i] - stones[i-1] > i)
            {
                return false;
            }
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = i - 1; j >=0; j--)
            {
                int k = stones[i] - stones[j];
                if(k > j + 1)  // 在第j个石子上我们至多只能跳出j+1的距离
                {
                    break;
                }
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                if(i == n - 1 && dp[i][k])
                {
                    return true;
                }

            }
            
        }
        return false;
    }
};