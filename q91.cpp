#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if(s[0] == '0')
            return 0;
        
        if(len == 1)
        {
            return 1;
        }
        vector<int> ans(len);

        ans[0] = 1;
        int part = stoi(s.substr(0, 2));
        if(part <= 26)
        {
            ans[1]++;
        }
        if(s[1] != '0')
        {
            ans[1] += ans[0];
        }
        for(int i = 2; i < len; i++)
        {
            int c = s[i] - '0';
            part = stoi(s.substr(i-1, 2));
            if(c >  0 && c <= 9)
            {
                ans[i] += ans[i-1];
            }    
            if(part >= 10 && part <= 26)
            {
                ans[i] += ans[i-2];
            }
        }
        return ans[len - 1];


    }
};

// int numDecodings(string s) {
//     int len = s.size();
//     if(s[0] == '0')
//         return 0;
    
//     if(len == 1)
//     {
//         return 1;
//     }
//     int ans[len] = {0};
//     ans[0] = 1;
//     int part = stoi(s.substr(0, 2));
//     if(part <= 26)
//     {
//         ans[1]++;
//     }
//     if(s[1] != '0')
//     {
//         ans[1] += ans[0];
//     }
//     for(int i = 2; i < len; i++)
//     {
//         int c = s[i] - '0';
//         part = stoi(s.substr(i-1, 2));
//         if(c >  0 && c <= 9)
//         {
//             ans[i] += ans[i-1];
//         }    
//         if(part >= 10 && part <= 26)
//         {
//             ans[i] += ans[i-2];
//         }
//     }
//     return ans[len - 1];
// }

// int main()
// {
//     string test = "10";
//     cout << numDecodings(test) << endl;
//     cin.get();
//     return 0;
// }