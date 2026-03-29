class Solution {
public:
    bool matched(auto& f1, auto& f2){
        for(int i = 0 ;i < 128; i++){
            if(f2[i] < f1[i])return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        int ansLen = 1e9;
        string ans= "";
        vector<int> freq1(128,0),freq2(128,0);
        for(auto it:t){
            freq1[it]++;
        }
        while(right < s.size()){
            freq2[s[right]]++;
            int windowSize = right - left + 1;
            if(windowSize >= t.size()){
                while(left <= right && matched(freq1, freq2)){
                    int len = right - left + 1;
                    if(ansLen > len){
                        ansLen = len;
                        ans = s.substr(left , len);
                    }
                    freq2[s[left]]--;
                    left++;
                }
            }
            right++;
        }
        return ans;
    }
};
