#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int maxprofile = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            maxprofile = max(maxprofile, prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }

        return maxprofile;
    }
};