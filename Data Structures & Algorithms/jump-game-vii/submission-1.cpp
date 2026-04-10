class Solution {
public:
    bool solve(string s,int minJump,int maxJump,int index,auto& dp){
        if(index > s.size() || s[index]=='1')return false;
        if(index == s.size()-1)return true;
        if(dp[index] != -1)return dp[index];
        int n = s.size();
        for(int i = index+ minJump; i <= min(n-1,index+maxJump);i++){
            if(solve(s,minJump,maxJump,i,dp))return dp[index] = true;
        }
        return dp[index] = false;
    }
    bool canReach(string s, int minJump, int maxJump) {
        vector<int> dp(s.size(),-1);
        return solve(s,minJump,maxJump,0,dp);
    }
};