class Solution {
public:
    int solve(vector<int>& nums,int index,int prev,auto& dp){
        if(index < 0)return 0;
        if(dp[index][prev] != -1)return dp[index][prev];
        int take = 0;
        if(prev == nums.size() || nums[index] < nums[prev]){
            take = solve(nums, index-1, index, dp) + 1;
        } 
        int notTake = solve(nums,index-1, prev, dp);
        return dp[index][prev] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums,nums.size()-1,nums.size(),dp);
    }
};
