class Solution {
    public boolean isHappy(int n) {
        HashSet<Integer> visited = new HashSet<>();
        while(n != 1){
            if(visited.contains(n))return false;
            visited.add(n);
            int x = n;
            int num = 0;
            while(x > 0){
                num += (x%10)*(x%10);
                x /= 10;
            }
            n = num;
        }
        return true;
    }
}
