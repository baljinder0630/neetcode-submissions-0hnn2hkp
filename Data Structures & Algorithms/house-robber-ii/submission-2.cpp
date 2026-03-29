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
        vector<int> dp(nums.size()+2,0), dp2(nums.size()+2,0);

        for(int index=nums.size()-2; index>=0; index--){
            int notRob = dp[index+1];
            int rob = dp[index+2] + nums[index];
            dp[index] = max(rob, notRob);
        }
        for(int index=nums.size()-1; index>0; index--){
            int notRob = dp2[index+1];
            int rob = dp2[index+2] + nums[index];
            dp2[index] = max(rob, notRob);
        }
        return max(dp[0], dp2[1]);
    }
};
