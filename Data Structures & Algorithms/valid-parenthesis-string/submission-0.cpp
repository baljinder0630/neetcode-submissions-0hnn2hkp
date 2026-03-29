class Solution {
public:
    bool solve(string& s,int index,int left,int right,auto& dp){
        if(right > left)return false;
        if(index == s.size()){
            return left == right;
        }
        if(dp[index][left][right] != -1)return dp[index][left][right];
        if(s[index] == '(')return dp[index][left][right] = solve(s,index+1,left+1,right,dp);
        if(s[index] == ')')return dp[index][left][right] =  solve(s,index+1,left,right+1,dp);
        return dp[index][left][right] =  solve(s,index+1,left+1,right,dp) || solve(s,index+1,left,right+1,dp) || solve(s,index+1,left,right,dp);
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1, vector<int>(n+1, -1))); // ❌ dp init missing
        return solve(s,0,0,0,dp);
    }
};
