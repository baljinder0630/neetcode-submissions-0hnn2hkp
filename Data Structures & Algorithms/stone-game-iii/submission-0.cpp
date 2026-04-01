class Solution {
public:
    int solve(int index,int Alice,vector<int>& stoneValue,int& n,auto& dp){
        if(index >= stoneValue.size())return 0;
        if(dp[index][Alice] != -1)return dp[index][Alice];
        int res = Alice == 1 ? INT_MIN : INT_MAX;
        int score = 0;
        for(int i=index; i < min(index + 3, n); i++){
            if(Alice == 1){
                score += stoneValue[i];
                res = max(res,score + solve(i +1, 0 ,stoneValue,n,dp));
            }
            else{
                score -= stoneValue[i];
                res = min(res,score + solve(i+1, 1,stoneValue,n,dp));
            }
        }
        return dp[index][Alice] = res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int res = solve(0,1,stoneValue,n,dp);
        if(res == 0)return "Tie";
        if(res < 0)return "Bob";
        return "Alice";
    }
};