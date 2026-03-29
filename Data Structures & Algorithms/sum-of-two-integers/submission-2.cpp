class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b);   // common bits
            a = a ^ b;             // sum without carry
            b = carry << 1;        // shift carry
        }
        return a;
    }
};