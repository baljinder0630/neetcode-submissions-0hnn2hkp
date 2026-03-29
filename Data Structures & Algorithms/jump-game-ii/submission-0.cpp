class Solution {
public:
    int solve(auto& nums, int i,auto& dp){
        if(i >= nums.size()-1)return 0;
        if(dp[i] != -1)return dp[i];
        int ans = 1e9;
        for(int jump=1; jump<= nums[i]; jump++){
            ans = min(ans, solve(nums, i + jump, dp) + 1);
        }
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};
