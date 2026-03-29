class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m1,m2;
        for(auto it:s1){
            m1[it]++;
        }
        for(int i=0;i<s2.size();i++){
            if(i >= s1.size()){
                m2[s2[i-s1.size()]]--;
                if(m2[s2[i-s1.size()]] == 0)m2.erase(s2[i-s1.size()]);
            }
            m2[s2[i]]++;
            if(m1 == m2)return true;
        }
        return false;
    }
};
