class Solution {
public:
    int solve(vector<int>& nums,int index,int end,vector<int>& dp){
        if(index >= end)return 0;
        if(dp[index] != -1)return dp[index];
        int notRob = solve(nums,index+1,end,dp);
        int rob = solve(nums,index+2,end,dp) + nums[index];
        return dp[index] = max(rob, notRob);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        vector<int> dp(nums.size(),-1), dp2(nums.size(),-1);
        return max(solve(nums,1,nums.size(),dp2), solve(nums,0,nums.size()-1,dp));
    }
};
