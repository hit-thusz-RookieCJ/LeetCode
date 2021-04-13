#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxsqure = min(height[l], height[r]) * (r - l);
        while(l < r)
        {
            if(height[l] <= height[r])
            {
                int temp = height[l];
                while(l < r && height[l] <= temp) l++;
            }
            else
            {
                int temp = height[r];
                while(r > l && height[r] <= temp) r--;
            }
            maxsqure = max(maxsqure, (min(height[l], height[r]) * (r - l)));
        }
        return maxsqure;
    }


};   


// int maxArea(vector<int>& height) {
//     int l = 0;
//     int r = height.size() - 1;
//     int maxsqure = min(height[l], height[r]) * (r - l);
//     while(l < r)
//     {
//         // cout << l << "  " << r << endl;
//         if(height[l] <= height[r])
//         {
//             cout << 1 << endl;
//             int temp = height[l];
//             while(l < r && height[l] <= temp) 
//                 l++;
//             maxsqure = max(maxsqure, (min(height[l], height[r]) * (r - l)));
//         }
//         else
//         {
//             cout << 2 << endl;
//             int temp = height[r];
//             while(r > l && height[r] <= temp) 
//                 r--;
//             maxsqure = max(maxsqure, (min(height[l], height[r]) * (r - l)));
//         }
//     }
//     return maxsqure;
// }

// int main()
// {
//     vector<int> test = {1,8,6,2,5,4,8,3,7};
//     cout << maxArea(test);
//     cin.get();
//     return 0;
// }