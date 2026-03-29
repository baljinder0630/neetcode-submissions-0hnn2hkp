class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int right = 0;
        int maxi = prices[0], mini = prices[0];
        int ans = 0 ;
        while(right < prices.size()){
            if(prices[right] > mini){
                maxi = prices[right];
                ans = max(ans, maxi - mini);
            }
            if(prices[right] < mini){
                mini = prices[right];
            }
            right++;
        }
        return ans;
    }
};
