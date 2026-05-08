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
    int ans;
    public Solution(){
        ans = 0;
    }
    public void solve(TreeNode root,int maxi){
        if(root == null)return;
        if(root.val >= maxi)ans++;
        maxi = Math.max(root.val,maxi);
        solve(root.left,maxi); 
        solve(root.right,maxi); 
    }
    public int goodNodes(TreeNode root) {
        solve(root,root.val);
        return ans;
    }
}
