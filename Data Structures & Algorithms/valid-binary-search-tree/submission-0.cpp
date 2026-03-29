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
    pair<int,int> solve(TreeNode* root,bool& ans){
        if(root==NULL)return {-1e9,1e9};
        pair<int,int> left = solve(root->left,ans);
        pair<int,int> right = solve(root->right,ans);
        if(root->val <= left.first || root->val >= right.second){
            ans = false;
        }
        return {max(root->val,right.first),min(root->val,left.second)};
    }
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        solve(root,ans);
        return ans;
    }
};
