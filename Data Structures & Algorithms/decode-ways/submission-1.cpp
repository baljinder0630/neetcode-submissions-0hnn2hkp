class Solution {
public:
    int solve(int index,string& s,auto& dp){
        if(index >= s.size())return 1;
        if(dp[index] != -1)return dp[index];
        // single char
        int ans = 0;
        if(s[index] >= '1' && s[index] <= '9'){
            ans = solve(index + 1, s, dp);
            if(index < s.size()-1){
                if(s[index] == '1' && s[index+1] >= '0' && s[index+1] <= '9'){
                    ans += solve(index+2,s, dp);
                }
                if(s[index] == '2' && s[index+1] >= '0' && s[index+1] <= '6'){
                    ans+= solve(index+2,s ,dp);
                }
            }
        }
        return dp[index] = ans;
    }   
    int numDecodings(string s) {
        vector<int> dp(s.size()+2,0);
        dp[s.size()] = 1;
        dp[s.size()+1] = 1;
        for(int index = s.size()-1; index >= 0 ; index--){
            int ans = 0;
            if(s[index] >= '1' && s[index] <= '9'){
                ans = dp[index + 1];
                if(index < s.size()-1){
                    if(s[index] == '1' && s[index+1] >= '0' && s[index+1] <= '9'){
                        ans += dp[index+2];
                    }
                    if(s[index] == '2' && s[index+1] >= '0' && s[index+1] <= '6'){
                        ans+= dp[index+2];
                    }
                }
            }
            dp[index] = ans;
        }
        return dp[0];
    }
};
