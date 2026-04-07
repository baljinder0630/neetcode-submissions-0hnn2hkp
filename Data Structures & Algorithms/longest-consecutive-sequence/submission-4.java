class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> s = new HashSet<>();
        for(int i=0;i<nums.length;i++){
            s.add(nums[i]);
        } 
        int ans = 0;
        for(int val:nums){
            if(!s.contains(val-1)){
                int len = 0;
                while(s.contains(val)){
                    len++;
                    val++;
                    ans = Math.max(len, ans);
                }
            }
        }
        return ans;
    }
}
