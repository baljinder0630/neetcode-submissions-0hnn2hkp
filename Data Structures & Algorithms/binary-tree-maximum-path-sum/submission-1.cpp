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
    int solve(TreeNode* root,int& ans){
        if(root==NULL)return 0;
        int left = solve(root->left,ans);
        int right = solve(root->right,ans);
        ans = max({ans, root->val, root->val+left+right});
        return max(0,root->val+max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        int ans = -1e9;
        solve(root,ans);
        return ans;
    }
};
