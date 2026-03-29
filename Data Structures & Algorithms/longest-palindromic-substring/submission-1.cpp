class Solution {
public:
    bool isPalindrome(string s,int i,int j){
        while(i <= j){
            if(s[i] != s[j])return false;
            i++,j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int maxLen = 0;
        string ans = "";
        for(int i=0;i < s.size(); i++){
            for(int len = 0; i+len < s.size(); len++){
                if(isPalindrome(s,i,i+len)){
                    if(len+1 > maxLen){
                        maxLen = len+1;
                        ans = s.substr(i,len+1);
                    }
                }
            }
        }
        return ans;
    }
};
