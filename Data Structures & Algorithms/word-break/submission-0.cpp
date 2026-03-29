class Solution {
public:
    bool solve(string s,auto& dict,int i,auto& dp){
        if(i == s.size())return true;
        if(dp[i] != -1)return dp[i];
        for(int index=i;index<s.size();index++){
            if(dict.count(s.substr(i,index-i+1))){
                if(solve(s,dict,index+1,dp))return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size(),-1);
        return solve(s,dict,0,dp);
    }
};
