#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void midsearch(TreeNode* root, int& count, int low, int high, int flag)
    {
        if(root == nullptr || flag == 2)
        {
            return;
        }

        midsearch(root->left, count, low, high, flag);

        if(root->val >= low)
        {
            flag = 1;
        }

        if(root->val > high)
        {
            flag = 2;
        }

        if(flag == 1)
        {
            count += root->val;
        }

        midsearch(root->right, count, low, high, flag);

    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int count = 0, flag = 0;
        midsearch(root, count, low, high, flag);
        return count;
    }
};