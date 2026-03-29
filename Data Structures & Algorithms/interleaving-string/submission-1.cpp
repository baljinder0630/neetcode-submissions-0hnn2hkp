class Solution {
public:
    bool solve(string s1,string s2,string s3, int i,int j,auto& dp){
        if(i == s1.size() && j == s2.size())return true;
        if(dp[i][j] != -1)return dp[i][j];
        int k = i+j;
        bool ans = false;
        if(i < s1.size() && s1[i] == s3[k]){
            ans = solve(s1,s2,s3,i+1,j,dp);
        }
        if(j < s2.size() && s2[j] == s3[k]){
            ans = ans || solve(s1,s2,s3,i,j+1,dp);
        }
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size() , l2 = s2.size();
        if(l1 + l2 != s3.size())return false;
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));
        return solve(s1,s2,s3,0,0,dp);
    }
};
