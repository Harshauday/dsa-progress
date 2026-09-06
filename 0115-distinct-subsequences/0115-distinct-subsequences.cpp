class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // We use unsigned long long instead of int here.
        // Even though the final answer fits in a 32-bit signed integer, 
        // intermediate DP calculations in C++ can exceed this limit on strict 
        // test cases, causing a runtime error (signed integer overflow is Undefined Behavior).
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1; // Base case: 1 way to form an empty string t
        
        for (int i = 1; i <= m; i++) {
            // Iterate backwards to prevent reusing the current character
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return dp[n];
    }
};