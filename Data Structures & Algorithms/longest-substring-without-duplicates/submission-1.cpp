class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, ans =0;
        unordered_map<char,int> m;
        while(right < s.size()){
            if(m.count(s[right])){
                left = max(left, m[s[right]] + 1);
            }
            m[s[right]] = right;
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
