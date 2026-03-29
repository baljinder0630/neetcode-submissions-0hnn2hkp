class Solution {
public:
    int solve(vector<int>& coins,int amount,int index, auto& dp){
        if(amount == 0)return 0;
        if(amount < 0)return 1e9;
        if(index == coins.size())return 1e9;
        if(dp[index][amount] != -1)return dp[index][amount];
        int take = solve(coins,amount-coins[index],index,dp)+1;
        int notTake = solve(coins, amount,index+1,dp);
        return dp[index][amount] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = solve(coins,amount,0, dp);
        return ans == 1e9 ? -1: ans;
    }
};
