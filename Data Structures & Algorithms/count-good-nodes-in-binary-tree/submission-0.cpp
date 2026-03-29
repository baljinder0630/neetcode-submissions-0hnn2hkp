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
    int solve(TreeNode* root,int val){
        if(root==NULL)return 0;
        int left = solve(root->left,max(val,root->val));
        int right = solve(root->right,max(val,root->val));
        // if((val < root->val)){
        //     cout<<root->val << " " << val << endl;
        // }
        return left+right+ (val <= root->val);
    }
    int goodNodes(TreeNode* root) {
        return solve(root,-1e9);
    }
};
