class Solution {
public:
    int solve(int amount, auto& coins,int index,auto& dp){
        if(index == coins.size()){
            return amount == 0;
        }
        if(amount < 0)return 0;
        if(dp[amount][index] != -1)return dp[amount][index];
        int notTake = solve(amount , coins, index+1, dp);
        int take = solve(amount - coins[index], coins, index, dp);
        return dp[amount][index] = take + notTake ;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size(), -1));
        return solve(amount, coins, 0, dp);
    }
};
