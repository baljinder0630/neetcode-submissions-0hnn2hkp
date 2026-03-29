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
        memo = new Boolean[nums.length+1][total/2 + 1];
        for(int i=0; i <= nums.length; i++){
            memo[i][0] = true;
        }
        for(int s = 1; s <= total/2; s++){
            memo[nums.length][s] = false;
        }
        for(int index = nums.length-1; index >= 0; index--){
            for(int sum = 1; sum <= total/2; sum++){
                boolean notTake = memo[index+1][sum];
                boolean take = false;
                if(sum - nums[index] >= 0)
                take = memo[index+1][sum-nums[index]];
                memo[index][sum] = take || notTake;
            }
        }
        return memo[0][total / 2];
    }
}
