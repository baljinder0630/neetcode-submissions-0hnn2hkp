class Solution {
public:


    int solve(vector<int>& piles, int i, int n, int M,auto& dp) {
        if (i >= n) return 0;

        if (dp[i][M] != -1) return dp[i][M];

        // ❌ you used accumulate every time (slow but ok logically)
        // keep it but better to optimize later
        if (i + 2 * M >= n)
            return dp[i][M] = accumulate(piles.begin() + i, piles.end(), 0);

        int ans = 0;

        for (int X = 1; X <= 2 * M; X++) {
            int opponent = solve(piles, i + X, n, max(M, X),dp);

            // ❌ WRONG: sum - opponent
            // ✅ FIX: total remaining - opponent
            int total = accumulate(piles.begin() + i, piles.end(), 0);

            ans = max(ans, total - opponent);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size()+1,vector<int>(piles.size()+1,-1));
        return solve(piles, 0, piles.size(), 1,dp);
    }
};