class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) i++; 
            // ❌ earlier you manually checked only letters; digits were missing

            while (i < j && !isalnum(s[j])) j--; 
            // ❌ you were checking s[i] instead of s[j] here

            if (tolower(s[i]) != tolower(s[j])) return false; 
            // ❌ comparison must be case-insensitive

            i++;
            j--;
        }
        return true;
    }
};
