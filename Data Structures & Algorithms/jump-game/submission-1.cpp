class Solution {
public:
    bool solve(vector<int>& nums,int index,auto& dp){
        if(index >= nums.size()-1)return true;
        if(dp[index] != -1)return dp[index];
        for(int i=1;i<=nums[index];i++){
            if(solve(nums,index+i,dp)){
                return dp[index] = true;
            }
        }
        return dp[index]= false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};
