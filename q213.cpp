#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int length = nums.size();
//         bool flag[length][2];
//         int m[length][2];

//         if(length == 1)
//         {
//             return nums[0];
//         }

//         m[0][0] = 0;
//         flag[0][0] = false;
//         m[0][1] = nums[0];
//         flag[0][1] = true;

//         for(int i = 1; i < length; i++)
//         {
//             if(m[i-1][0] > m[i-1][1])
//             {
//                 m[i][0] = m[i-1][0];
//                 flag[i][0] = flag[i-1][0];
//             }
//             else
//             {
//                 m[i][0] = m[i-1][1];
//                 flag[i][0] = flag[i-1][1];
//             }

//             m[i][1] = m[i-1][0] + nums[i];
//             flag[i][1] = flag[i-1][0];

//             if(i == length - 1 && flag[i - 1][0] == true)
//             {
//                 m[i][1] = m[i][0];
//             }

//         }
//         return max(m[length-1][0], m[length-1][1]);

//     }
// };

class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int first = nums[start], second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) {
            return nums[0];
        } else if (length == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
    }
};
