class Solution {
    private boolean isPossible(int[] piles,double num,int h){
        int count = 0;
        for(int pile:piles){
            count += Math.ceil(pile/num);
            if(count > h)return false;
        }
        return true;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int maxi = 0;
        for(int pile:piles){
            maxi = Math.max(pile,maxi);
        }
        int left = 1, right = maxi;
        int ans = -1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(isPossible(piles,mid,h)){
                System.out.println(mid);
                right = mid-1;
                ans = mid;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
}
