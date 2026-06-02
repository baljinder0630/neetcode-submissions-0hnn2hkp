class Solution {
    int[][] dp;
    private int solve(int[] prices,int index, boolean isBuy){
        if(index == prices.length){
            return 0;
        }
        if(dp[index][isBuy ? 1 : 0] != -1)return dp[index][isBuy ? 1 : 0];
        int skip = solve(prices,index+1,isBuy);
        int buy = isBuy ? solve(prices,index+1,false) - prices[index] : 0;
        int sell = isBuy ? 0 : solve(prices, index+1, true) + prices[index];
        return dp[index][isBuy ? 1 : 0] = Math.max(skip, Math.max(buy, sell));
    }
    public int maxProfit(int[] prices) {
        dp = new int[prices.length][2];
        for(int i=0;i<prices.length; i++){
            Arrays.fill(dp[i], -1);
        }
        return solve(prices, 0, true);
    }
}