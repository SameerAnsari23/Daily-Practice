class Solution {
public:
    int longestValidParentheses(string s) {
        /* Using stack  T.C - O(n)  S.C - O(n)
        stack<int>st;
        st.push(-1);
        int maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();
                if (st.empty()) {
                    // Reset Boundary
                    st.push(i);
                }
                maxlen = max(maxlen, i - st.top());
            }
        }
        return maxlen;
        */



        int open = 0, close = 0, maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open++;
            }
            else {
                close++;
            }
            if (open == close) {
                maxlen = max(maxlen, 2 * close);
            } 
            else if (close > open) {
                close = 0;
                open = 0;
            }
        }

        // reset open and close
        open = 0; close = 0;

        // right to left
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                open++;
            }
            else {
                close++;
            }
            if (open == close) {
                maxlen = max(maxlen, 2 * open);
            } 
            else if (close < open) {
                close = 0;
                open = 0;
            }
        }
        return maxlen;
    }
};
