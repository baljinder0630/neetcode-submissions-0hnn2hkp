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
    private int solve(TreeNode root,int maxi){
        if(root == null)return 0;
        maxi = Math.max(root.val,maxi);
        int left = solve(root.left,maxi);
        int right = solve(root.right,maxi);
        return left + right + ((root.val >= maxi) ? 1 : 0);
    }
    public int goodNodes(TreeNode root) {
        return solve(root,root.val);
    }
}
