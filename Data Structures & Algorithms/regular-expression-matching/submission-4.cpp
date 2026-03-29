class Solution {
public:
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if (i == s.length() && j == p.length()) // both strings are fully matched
            return true;
        if (j == p.length()) // pattern is exhausted, but string is not
            return false;
        if (dp[i][j] != -1) // return previously computed result
            return dp[i][j];

        bool match = (i < s.length() && (s[i] == p[j] || p[j] == '.')); // check if current characters match

        // Handle '*' in the pattern
        if (j + 1 < p.length() && p[j + 1] == '*') {
            // Option 1: '*' acts as zero occurrences of the preceding character
            // Option 2: '*' matches one or more occurrences of the preceding character if the current character matches
            return dp[i][j] = solve(s, p, i, j + 2, dp) || (match && solve(s, p, i + 1, j, dp));
        }

        // Proceed with the next characters if current characters match
        if (match) {
            return dp[i][j] = solve(s, p, i + 1, j + 1, dp);
        }

        return dp[i][j] = false; // if no conditions match, return false
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
        return solve(s, p, 0, 0, dp);
    }
};