class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1, suffix =1;
        int ans = -1e9;
        for(int i=0;i<nums.size();i++){
            prefix *= nums[i];
            suffix *= nums[nums.size()-1-i];
            ans = max({ans, prefix, suffix});
            if(prefix == 0)prefix = 1;
            if(suffix == 0)suffix = 1;
        }
        return ans;
    }
};
