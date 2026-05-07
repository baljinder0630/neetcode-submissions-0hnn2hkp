class Solution {
    public int reverse(int x) {
        final int MIN = Integer.MIN_VALUE;
        final int MAX = Integer.MAX_VALUE;
        int ans = 0;
        while(x != 0){
            int digit = x % 10;
            if(ans < MIN / 10 || (ans == MIN / 10 && MIN % 10 > digit))return 0;
            if(ans > MAX / 10 || (ans == MAX / 10 && MAX % 10 < digit))return 0;
            ans = (ans * 10) + digit;
            x /= 10;
        }
        return ans;
    }
}
