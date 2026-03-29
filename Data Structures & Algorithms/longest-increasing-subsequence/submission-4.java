public class Solution {
    public int lengthOfLIS(int[] nums) {
        List<Integer> dp = new ArrayList<>();
        dp.add(nums[0]);
        for(int i=1;i<nums.length;i++){
            if(dp.get(dp.size()-1) < nums[i]){
                dp.add(nums[i]);
            }
            else{
                int lb = Collections.binarySearch(dp,nums[i]);
                if(lb < 0)lb = -(lb+1);
                dp.set(lb,nums[i]);
            }
        }
        return dp.size();
    }
}
