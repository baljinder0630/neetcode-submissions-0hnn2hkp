class Solution {
public:
    bool solve(vector<int>& nums,int index){
        if(index >= nums.size()-1)return true;
        for(int i=1;i<=nums[index];i++){
            if(solve(nums,index+i)){
                return true;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        return solve(nums,0);
    }
};
