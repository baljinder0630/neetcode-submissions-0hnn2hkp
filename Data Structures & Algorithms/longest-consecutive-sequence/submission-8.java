class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0)return 0;
        Map<Integer,Integer> indices = new HashMap<>();
        for(int i=0;i < nums.length; i++){
            indices.put(nums[i],i);
        }
        int ans=1;
        for(int i=0;i < nums.length; i++){
            if(indices.getOrDefault(nums[i]-1,-1) != -1)continue;
            int len = 1;
            int num = nums[i]+1;
            while(indices.getOrDefault(num,-1) != -1){
                len++;
                ans = Math.max(ans, len);
                num++;
            }
        }
        return ans;
    }
}
