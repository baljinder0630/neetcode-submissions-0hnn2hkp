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
        // vector<vector<int>> dp(prices.size()+2,vector<int>(2,0));
        vector<int> next(2,0), curr(2,0), next2(2,0);
        for(int index = prices.size()-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                if(buy){
                    curr[buy] = max({
                        curr[buy],
                        next[buy],
                        next[false] - prices[index]
                    });
                }
                else{
                    curr[buy] = max({
                        curr[buy],
                        next[buy],
                        next2[true] + prices[index]
                    });
                }
                next2 = next;
                next = curr;
            }
        }
        return curr[true];
    }
};
