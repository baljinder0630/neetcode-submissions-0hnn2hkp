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
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i == m && j != n)dp[i][j] = n-j;
                if(j == n && i != m)dp[i][j] = m-i;
            }
        }
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0 ;j--){
                int ans = 1e9;
                if(word1[i] == word2[j])ans = dp[i+1][j+1];
                else{
                    int insert = dp[i][j+1]+1;
                    int deleteCh = dp[i+1][j]+1;
                    int replace = dp[i+1][j+1]+1;
                    ans = min({ans,insert,deleteCh,replace});
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};
