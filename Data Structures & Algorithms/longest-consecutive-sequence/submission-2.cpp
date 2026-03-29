class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it:nums){
            s.insert(it);
        }
        int ans = 0;
        for(auto it:nums){
            int count = 0;
            int num = it;
            while(s.count(num)){
                s.erase(num);
                num--;
                count++;
            }
            num=it+1;
            while(s.count(num)){
                s.erase(num);
                num++;
                count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
