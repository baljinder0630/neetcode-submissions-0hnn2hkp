/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int solve(TreeNode* root,bool& ans){
        if(root==NULL)return 0;
        int left = solve(root->left,ans);
        int right = solve(root->right,ans);
        ans &= abs(right - left) <= 1;
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        solve(root,ans);
        return ans;
    }
};
