class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character,Integer> m = new HashMap<>();
        int ans = 0;
        int i = -1, j = 0;
        while(j < s.length()){
            if(m.containsKey(s.charAt(j))) i = Math.max(i,m.get(s.charAt(j)));
            m.put(s.charAt(j), j);
            ans = Math.max(ans , j-i);
            j++;
        }
        return ans;
    }
}
