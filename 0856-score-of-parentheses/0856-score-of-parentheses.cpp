#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);  // Base score for the current frame

        for (char ch : s) {
            if (ch == '(') {
                // Start a new frame with score 0
                st.push(0);
            } else {
                // End of a frame, pop the inside score
                int inside = st.top();
                st.pop();

                // If inside is 0, it means "()" which scores 1
                // Otherwise, score is 2 * inside
                int top = st.top();
                st.pop();
                st.push(top + (inside == 0 ? 1 : 2 * inside));
            }
        }

        return st.top();
    }
};
