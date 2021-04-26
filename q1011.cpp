#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right)
        {
            int mid = (left + right) / 2;
            int need_day = 1, cur_weight = 0;
            for(int weight : weights)
            {
                if(cur_weight + weight > mid)
                {
                    cur_weight = 0;
                    need_day++;
                }
                cur_weight += weight;
            }

            if(need_day <= D)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;

    }
};