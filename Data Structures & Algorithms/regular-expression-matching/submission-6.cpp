class Solution {
public:
    int solve(string s,string p,int i,int j,auto& dp){
        if(j == p.size())return  i == s.size();
        // if(i >= s.size())return false;
        bool match = (i < s.size()) && (s[i] == p[j] || p[j] == '.');
        if(dp[i][j] != -1)return dp[i][j];
        if(j < p.size()-1 && p[j+1] == '*')return dp[i][j] = solve(s,p,i,j+2,dp) ||(match && solve(s,p,i+1,j,dp));
        if(p[j] == '*')return dp[i][j] = solve(s,p,i,j+1,dp);
        return dp[i][j] = match && solve(s,p,i+1,j+1,dp);
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(s,p,0,0,dp);
    }
};
