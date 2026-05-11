class Solution {
    int[][] dp;
    private int solve(int[] coins,int amount,int index){
        if(amount == 0)return 0;
        if(index == coins.length)return 1000000009;
        if(dp[index][amount] != -1)return dp[index][amount];
        int notTake = solve(coins,amount,index+1);
        int take  = amount >= coins[index] ? 1+solve(coins,amount-coins[index],index) : 1000000009;
        return dp[index][amount] = Math.min(take,notTake);
    }
    public int coinChange(int[] coins, int amount) {
        dp = new int[coins.length][amount+1];
        for(int i=0;i<coins.length;i++){
            for(int j=0;j<=amount;j++){
                dp[i][j]=-1;
            }
        }
        int ans = solve(coins,amount,0);
        return ans == 1000000009 ? -1 : ans;
    }
}
