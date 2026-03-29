class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = -1e9;
        for(int i=0;i<nums.size();i++){
            int product = 1;
            for(int j=i; j <nums.size();j++){
                product*=nums[j];
                ans = max(ans,product);
                if(product == 0)product = 1;
            }
        }
        return ans;
    }
};
