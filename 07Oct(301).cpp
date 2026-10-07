class Solution {
public:
    void solve(string &s, int i, string &curr, int open, int &maxLen, set<string> &st) {
        if (open < 0) return ;
        if (i == s.length()) {
            if (open == 0) {
                if (curr.length() > maxLen) {
                    maxLen = curr.length();
                    st.clear();
                }
                if (curr.length() == maxLen) {
                    st.insert(curr);
                }
            }
            return ;
        }

        if (s[i] != '(' && s[i] != ')') {
            curr.push_back(s[i]);
            solve(s, i+1, curr, open, maxLen, st);
            curr.pop_back();
            return;
        }

        curr.push_back(s[i]);
        solve(s, i+1, curr, open+(s[i] == ')' ? -1 : 1), maxLen, st);
        curr.pop_back();
        solve(s, i+1, curr, open, maxLen, st);;
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string>st;
        string curr = "";
        int maxLen = 0;
        solve(s, 0, curr, 0, maxLen, st);
        return vector<string>(st.begin(), st.end());        
    }
};
