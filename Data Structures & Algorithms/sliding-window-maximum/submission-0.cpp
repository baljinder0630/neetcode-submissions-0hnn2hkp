class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<pair<int,int>> s;
        int left = 0, right = 0;
        vector<int> ans;
        while(right < k){
            s.insert({nums[right], right});
            right++;
        }
        ans.push_back(s.rbegin()->first);
        while(right < nums.size()){
            s.erase({nums[left],left});
            left++;
            s.insert({nums[right], right});
            ans.push_back(s.rbegin()->first);
            right++;
        }
        return ans;
    }
};
