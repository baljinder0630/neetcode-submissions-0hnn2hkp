class Solution {
public:
    unordered_map<int,int> dp;
    int numSquares(int n) {
        if(n == 1)return 1;
        if(dp.count(n))return dp[n];
        int ans = n;
        for(int i = n/2; i >= 1; i--){
            if(i * i <= n){
                ans = min(ans , 1 + numSquares(n - (i*i)));
            }
        }
        return dp[n] = ans;
    }
};