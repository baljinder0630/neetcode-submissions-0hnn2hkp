class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int start = 0; start <= s.size(); start++){
            int i=start,j=start;
            while(i >= 0 && j < s.size()){
                if(s[i] != s[j])break;
                i--,j++;
                ans++;
            }
            i=start,j=start+1;
            while(i >= 0 && j < s.size()){
                if(s[i] != s[j])break;
                i--,j++;
                ans++;
            }
        }
        return ans;
    }
};
