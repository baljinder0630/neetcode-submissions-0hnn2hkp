class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while(n != 1){
            if(visited.count(n))return false;
            visited.insert(n);
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
};
