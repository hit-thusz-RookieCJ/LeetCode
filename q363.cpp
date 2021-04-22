#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        bool isRight = m > n;
        vector<int> sum((isRight ? m + 1 : n + 1), 0);
        int ans = INT_MIN;
        for(int i = 1; i <= (isRight ? m : n); i++)
        {
            fill(sum.begin(), sum.end(), 0);
            for(int j = i; j <=(isRight ? m : n); j++)
            {
                set<int> st;
                st.insert(0);
                int a = 0;
                for(int fixed = 1; fixed <= (isRight ? n : m); fixed++)
                {
                    sum[fixed] += isRight ?  matrix[j - 1][fixed - 1] : matrix[fixed - 1][j - 1];
                    a += sum[fixed];
                    auto b = st.lower_bound(a - k);
                    if(b != st.end())
                    {
                        int cur = a - *b;
                        ans = max(cur, ans);
                    }
                    st.insert(a);
                }
            }
        }
        return ans;
    }
};