class Solution {
public:
    int solve(string word1,string word2,int i,int j,auto& dp){
        if(j == word2.size()){
            return word1.size()-i;
        }
        if(i == word1.size()){
            return word2.size() - j;
        }
        if(dp[i][j] != -1)return dp[i][j];
        int ans = 1e9;
        if(word1[i] == word2[j])ans = solve(word1,word2,i+1,j+1,dp);
        else{
            int insert = solve(word1,word2,i,j+1,dp)+1;
            int deleteCh = solve(word1, word2, i+1,j,dp)+1;
            int replace = solve(word1,word2,i+1,j+1,dp)+1;
            ans = min({ans,insert,deleteCh,replace});
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return solve(word1,word2,0,0,dp);
    }
};
