class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i < n ;i++){
            int a = nums[i];
            int left = i+1;
            int right = n-1;
            while(left < right && right < n){
                int sum = a + nums[left] + nums[right];
                if(sum == 0){
                    ans.push_back({a,nums[left],nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1])left++;
                    while(left < right && nums[right] == nums[right+1])right--;
                }
                else if(sum > 0){
                    right--;
                }
                else{
                    left++;
                }
            }
            while(i < n-1 && nums[i] == nums[i+1])i++;
        }
        return ans;
    }
};
