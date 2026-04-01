class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long sum = 0;
        int i=0,j=0;
        int ans = 1e9;
        while(j<nums.size()){
            sum += nums[j];
            while(i <= j && sum >= target){
                ans = min(ans, j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return ans==1e9 ? 0:ans;
    }
};