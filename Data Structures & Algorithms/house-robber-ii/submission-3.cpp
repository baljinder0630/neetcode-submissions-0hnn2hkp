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
        int rob1 = 0, rob2 = 0, rob3;
        int rob4 = 0, rob5 = 0, rob6;
        for(int index=nums.size()-2; index>=0; index--){
            int notRob = rob1;
            int rob = rob2 + nums[index];
            rob3 = max(rob, notRob);
            rob2 = rob1;
            rob1 = rob3;
        }
        for(int index=nums.size()-1; index>0; index--){
            int notRob = rob4;
            int rob = rob5 + nums[index];
            rob6 = max(rob, notRob);
            rob5 = rob4;
            rob4 = rob6;
        }
        return max(rob3, rob6);
    }
};
