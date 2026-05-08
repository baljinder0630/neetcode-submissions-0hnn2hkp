/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    int k;
    int solve(TreeNode root){
        if(root == null)return -1;
        int left = solve(root.left);
        k--;
        if(k == 0)return root.val;
        int right = solve(root.right);
        if(left != -1 )return left;
        if(right != -1 )return right;
        return -1;
    }
    public int kthSmallest(TreeNode root, int K) {
        k = K;
        return solve(root);
    }
}
