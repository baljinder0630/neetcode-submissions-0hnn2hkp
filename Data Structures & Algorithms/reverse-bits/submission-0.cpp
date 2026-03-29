class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        int count = 0;
        while(count < 32){
            int x = 1 & n;
            n >>= 1;
            cout<<x;
            ans = ans | (x << (31-count));
            count++;
        }
        return ans;
    }
};
