class Solution {
public:
    int solve(int index,auto& prices,bool buy,auto& dp){
        if(index >= prices.size())return 0;
        if(dp[index][buy] != -1)return dp[index][buy];
        int ans = 0;
        if(buy){
            ans = max({
                ans,
                solve(index+1, prices, buy, dp),
                solve(index+1, prices, false, dp) - prices[index]
            });
        }
        else{
            ans = max({
                ans,
                solve(index+1, prices, buy, dp),
                solve(index+2, prices, true, dp) + prices[index]
            });
        }
        return dp[index][buy] = ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+2,vector<int>(2,0));
        for(int index = prices.size()-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                int ans = 0;
                if(buy){
                    ans = max({
                        ans,
                        dp[index+1][buy],
                        dp[index+1][false] - prices[index]
                    });
                }
                else{
                    ans = max({
                        ans,
                        dp[index+1][buy],
                        dp[index+2][true] + prices[index]
                    });
                }
                dp[index][buy] = ans;
            }
        }
        return dp[0][true];
    }
};
