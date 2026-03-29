class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it:nums){
            if(s.count(it))return true;
            s.insert(it);
        }
        return false;
    }
};