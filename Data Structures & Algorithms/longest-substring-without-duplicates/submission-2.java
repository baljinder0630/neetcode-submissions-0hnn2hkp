class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character,Integer> m = new HashMap<>();
        int i=-1,j=0;
        int ans = 0;
        while(j < s.length()){
            int idx = m.getOrDefault(s.charAt(j),-1);
            m.put(s.charAt(j),j);
            idx = Math.max(idx, i);
            if(i != idx)i = idx;
            ans = Math.max(j-i,ans);
            j++;
        }
        return ans;
    }
}
