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
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+2,0));
        for(int i=1;i<=amount+1;i++){
            dp[coins.size()][i]=1e9;;
        }
        for(int index = coins.size()-1; index >= 0; index--){
            for(int target = 0;target <= amount; target++){
                int take = 1e9;
                if(target >= coins[index])
                take = dp[index][target-coins[index]]+1;
                int notTake = dp[index+1][target];
                dp[index][target] = min(take,notTake);
            }
        }
        int ans = dp[0][amount];
        return ans == 1e9 ? -1: ans;
    }
};
