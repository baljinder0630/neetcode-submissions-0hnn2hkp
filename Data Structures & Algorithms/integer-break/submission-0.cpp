class Solution {
public:
    unordered_map<int,int> dp;
    int integerBreak(int n) {
        if(dp.count(n))return dp[n];
        int ans = 0;
        for(int i=1; i<n; i++){
            ans = max({ans, i*(n-i), i*integerBreak(n-i)});
        }
        return dp[n] = ans;
    }
};