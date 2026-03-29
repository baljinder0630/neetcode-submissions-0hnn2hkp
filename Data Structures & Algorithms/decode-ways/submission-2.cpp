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
        int a = 0, b = 1 , c = 1;
        for(int index = s.size()-1; index >= 0 ; index--){
            a = 0;
            if(s[index] >= '1' && s[index] <= '9'){
                a = b;
                if(index < s.size()-1){
                    if(s[index] == '1' && s[index+1] >= '0' && s[index+1] <= '9'){
                        a += c;
                    }
                    if(s[index] == '2' && s[index+1] >= '0' && s[index+1] <= '6'){
                        a+= c;
                    }
                }
            }
            c= b;
            b = a;
        }
        return a;
    }
};
