class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int maxWt = 0;
        for(auto it:stones){
            maxWt = max(maxWt, it);
        }
        vector<int> bucket(maxWt+1,0);
        for(auto it:stones){
            bucket[it]++;
        }
        int first = maxWt;
        while (first > 0) {

            while (first > 0 && bucket[first] == 0) first--; 
            // ❌ your code checked bucket[first] % 2 == 0 which is wrong.
            // We must skip only when there is NO stone of this weight.

            if (first == 0) return 0;

            bucket[first]--; 
            // ❌ your code used parity logic, but we must remove exactly ONE stone.

            int second = first;

            while (second > 0 && bucket[second] == 0) second--; 
            // ❌ your code checked bucket[second] % 2 == 0 which skips valid stones.

            if (second == 0) return first;

            bucket[second]--; 
            // ❌ your code set bucket[second] = 0 which removes ALL stones.

            bucket[first - second]++; 
            // new stone formed
        }
        return 0;
    }
};
