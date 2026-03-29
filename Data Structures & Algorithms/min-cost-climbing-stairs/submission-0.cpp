class Solution {
public:
    int solve(vector<int>& cost,int index,auto& dp){
        if(index >= cost.size())return 0;
        if(dp[index] != -1)return dp[index];
        int one = solve(cost,index+1,dp) + cost[index];
        int two = solve(cost,index+2,dp) + cost[index];
        return dp[index] = min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return min(solve(cost,0,dp),solve(cost,1,dp));
    }
};
