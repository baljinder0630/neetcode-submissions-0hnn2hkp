class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> s = new HashSet<>();
        for(int i=0;i<nums.length;i++){
            s.add(nums[i]);
        } 
        int ans = 0;
        for(int i=0;i<nums.length;i++){
            int val = nums[i];
            int len = 0;
            while(s.contains(val)){
                s.remove(val);
                // System.out.print(val + " ");
                len++;
                ans = Math.max(ans, len);
                val--;
            }
            val = nums[i]+1;
            while(s.contains(val)){
                // System.out.print(val + " ");
                s.remove(val);
                len++;
                ans = Math.max(ans, len);
                val++;
            }
            // System.out.println();
        }
        return ans;
    }
}
