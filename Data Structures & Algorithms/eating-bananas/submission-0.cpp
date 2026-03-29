class Solution {
public:
    bool isPossible(int k,auto& piles,int h){
        int hours = 0;
        for(auto it:piles){
            hours += (it + k - 1LL)/ k;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(isPossible(mid, piles, h)){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};
