class Solution {
    public int subarraySum(int[] nums, int k) {
        int ans = 0;
        Map<Integer,Integer> freq = new HashMap<>();
        freq.put(0,1);
        int sum = 0;
        for(int i=0;i<nums.length;i++){
            sum += nums[i];
            int diff = sum - k;
            ans += freq.getOrDefault(diff , 0);
            freq.put(sum,freq.getOrDefault(sum,0)+1);
        }
        return ans;
    }
}

