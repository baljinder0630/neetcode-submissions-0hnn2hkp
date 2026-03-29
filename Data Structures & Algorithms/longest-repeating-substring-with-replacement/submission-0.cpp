class Solution {
public:
    int countMf(auto& freq){
        int maxi = 0;
        for(auto it:freq){
            if(it.second > maxi){
                maxi = it.second;
            }
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int ans = 0;
        int left = 0, right = 0;
        while(right < s.size()){
            freq[s[right]]++;
            int windowSize = right - left + 1;
            int mf = countMf(freq);
            if(windowSize - mf > k){
                freq[s[left]]--;
                left++;
            }
            ans = max(ans , right - left + 1);
            right++;
        }
        return ans;
    }
};
