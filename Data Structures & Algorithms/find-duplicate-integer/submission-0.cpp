class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int curr = i;
            while(nums[curr] != -1){
                int next = nums[curr];
                nums[curr] = -1;
                curr = next;
            }
            if(nums[curr] == -1)return curr;
        }
        return -1;
    }
};
