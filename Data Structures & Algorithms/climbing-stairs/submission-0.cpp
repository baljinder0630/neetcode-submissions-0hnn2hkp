class Solution {
public: 
    int solve(int curr,int n,auto& dp){
        if(curr == n)return 1;
        if(dp[curr] != -1)return dp[curr];
        int ans = 0;
        ans += solve(curr+1, n, dp);
        if(curr <= n-2)
        ans += solve(curr+2, n, dp);
        return dp[curr] = ans;
    }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return solve(0,n,dp);
    }
};
