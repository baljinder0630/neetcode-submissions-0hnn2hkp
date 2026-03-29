class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m1,m2;
        for(auto it:s)m1[it]++;
        for(auto it:t)m2[it]++;
        return m1==m2;
    }
};
