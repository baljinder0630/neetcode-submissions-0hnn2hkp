class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> s = new HashSet<>();
        for(int i:nums){
            s.add(i);
        }
        int ans = 0;
        for(int i:nums){
            if(!s.contains(i-1)){
                int count = 0;
                while(s.contains(i)){
                    i++;
                    count++;
                }
                ans = Math.max(ans,count);
            }
        }
        return ans;
    }
}
