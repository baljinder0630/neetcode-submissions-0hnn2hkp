class Solution {
    private boolean isPossible(int mid,int[] piles,int h){
        int hr = 0;
        int n = piles.length;
        for(int i=0;i < n; i++){
            hr += Math.ceil((float) piles[i] / (double) mid);
            if(hr > h)break; 
        }
        return hr <= h;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int maxB = 0;
        int n = piles.length;
        for(int i= 0 ; i<n ; i++){
            maxB = Math.max(piles[i], maxB);
        }
        int s = 1, e = maxB;
        while(s <= e){
            int mid = (s+e)/2;
            if(isPossible(mid,piles,h)){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
}
