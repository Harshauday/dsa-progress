class Solution {
public:
    vector<string> ans;

    void backtrack(int n, int open, int close, string current) {
        if (open == n && close == n) {
            ans.push_back(current);
            return;
        }

        if (open < n) {
            backtrack(n, open + 1, close, current + '(');
        }

        if (close < open) {
            backtrack(n, open, close + 1, current + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack(n, 0, 0, "");
        return ans;
    }
};