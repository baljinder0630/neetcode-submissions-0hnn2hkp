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
    int preIndex = 0;
    TreeNode* create(vector<int>& preorder, vector<int>& inorder,int i,int j){
        if(i > j)return NULL;
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int k = i;
        for(; k <= j; k++){
            if(inorder[k] == root->val)break;
        }
        root->left = create(preorder,inorder,i,k-1);
        root->right = create(preorder,inorder,k+1,j);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create(preorder,inorder,0,preorder.size()-1);
    }
};
