class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";

        for (char ch : s) {
            if (ch == '(') {
                // If count > 0, this '(' is not an outer parenthesis
                if (count > 0) {
                    ans += ch; // Append the char directly
                }
                count++;
            } else {
                count--;
                // If count > 0 after decrementing, this ')' is not an outer parenthesis
                if (count > 0) {
                    ans += ch; // Append the char directly
                }
            }
        }
        return ans;
    }
};
