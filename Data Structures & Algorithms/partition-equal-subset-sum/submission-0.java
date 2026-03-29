class Solution {
    Boolean[][] memo;
    private boolean targetSum(int[] nums,int total,int index){
        if(total <= 0){
            return total == 0;
        }
        if(index == nums.length)return false;
        if(memo[index][total] != null)return memo[index][total];
        boolean notTake = targetSum(nums,total,index+1);
        boolean take = targetSum(nums,total-nums[index],index+1);
        return memo[index][total] = take || notTake;
    }
    public boolean canPartition(int[] nums) {
        int total = 0;
        for(int num:nums){
            total += num;
        }
        if(total % 2 != 0)return false;
        memo = new Boolean[nums.length][total/2 + 1];
        return targetSum(nums, total / 2, 0);
    }
}
