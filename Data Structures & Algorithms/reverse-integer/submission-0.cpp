class Solution {
public:
    void reverseString(string& s){
        int i=0, j = s.size()-1;
        while(i < j){
            swap(s[i++],s[j--]);
        }
    }

    int reverse(int x) {
        // int ans =0;
        bool sign = (x < 0) ? false : true;
        string s = to_string(x);
        if(!sign)s = s.substr(1);
        reverseString(s);
        int ans = 0;
        try{
            ans = stoi(s);
        }catch(const exception e){
            return 0;
        }
        if((sign && ans > INT_MAX) || (!sign && ans < INT_MIN) )return 0;
        return sign ? ans : -ans;
    }
};
