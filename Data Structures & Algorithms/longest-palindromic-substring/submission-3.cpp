class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        string ans = "";
        // odd len
        for(int start = 0; start < s.size(); start++){
            int i = start, j = start;
            while(i >= 0 && j < s.size()){
                if(s[i] != s[j])break;
                i--,j++;
            }
            i++,j--;
            int len = j - i + 1;
            if(len > maxLen){
                maxLen = len;
                ans = s.substr(i, len);
            }
        }
        // even len
        for(int start = 0; start < s.size(); start++){
            int i = start, j = start+1;
            while(i >= 0 && j < s.size()){
                if(s[i] != s[j])break;
                i--,j++;
            }
            i++,j--;
            int len = j - i + 1;
            if(len > maxLen){
                maxLen = len;
                ans = s.substr(i, len);
            }
        }
        return ans;
    }
};
