#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0;
        int right = (int)sqrt(c);
        while(left <= right)
        {
            int squre = left*left + right*right;
            if(squre == c)
            {
                return true;
            }
            else if(squre < c)
            {
                left++;
            }
            else
            {
                right--;
            }

        }
        return false;

    }
};


// bool judgeSquareSum(int c) {
//     int left = 0;
//     int right = (int)sqrt(c);
//     while(left <= right)
//     {
//         int squre = left*left + right*right;
//         if(squre == c)
//         {
//             return true;
//         }
//         else if(squre < c)
//         {
//             left++;
//         }
//         else
//         {
//             right--;
//         }

//     }
//     return false;

// }


// int main()
// {
//     int c = 6;
//     bool b = judgeSquareSum(c);
//     cout << b << endl;
//     cin.get();
//     return 0;

// }