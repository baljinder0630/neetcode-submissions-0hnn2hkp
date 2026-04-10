class Solution {
public:
    int solve(vector<int>& piles,int left,int right,auto& dp){
        if(left > right)return 0;
        if(dp[left][right] != -1)return dp[left][right];
        int takeLeft = piles[left] - solve(piles,left+1,right,dp);
        int takeRight = piles[right] - solve(piles,left,right-1,dp);
        return dp[left][right] = max(takeLeft,takeRight);
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),-1));
        return solve(piles,0,piles.size()-1,dp) > 0;
    }
};