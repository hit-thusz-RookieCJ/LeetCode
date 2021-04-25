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
    void mid_search(TreeNode* root, vector<int>& res)
    {

        if(root == nullptr)
        {
            return;
        }

        mid_search(root->left, res);

        res.push_back(root->val);

        mid_search(root->right, res);

    }
    
    TreeNode* increasingBST(TreeNode* root) {
        
        vector<int> res;
        mid_search(root, res);

        TreeNode *begin = new TreeNode();
        TreeNode *temp = begin;
        for(int val : res)
        {
            temp->right = new TreeNode(val);
            temp = temp->right;
        }

        return begin->right;
    }
};