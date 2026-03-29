class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum = 0;
        long long maxSum = -1e9;
        int left = 0, right = 0;
        while(right < nums.size()){
            sum += nums[right];
            if(sum > maxSum){
                maxSum = sum;
            }
            right++;
            if(sum < 0){
                left = right;
                sum = 0;
            }
        }
        return maxSum;
    }
};
