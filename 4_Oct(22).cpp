class Solution {
public:
    void solve(string op, int open, int close, int n, vector<string>& ans) {
        if (op.length() == 2*n) {
            // if (isValid(op)) ans.push_back(op);
            ans.push_back(op);
            return;
        }

        // op.push_back('(');
        // solve(op, n, ans);

        // op.pop_back();

        // op.push_back(')');
        // solve(op, n, ans);

        if (open < n) {
            op.push_back('(');
            solve(op, open+1, close, n, ans);
            op.pop_back();
        }
        
        if (close < open) {
            op.push_back(')');
            solve(op, open, close+1, n, ans);
            op.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string op;
        vector<string>ans;
        solve(op, 0, 0, n, ans);
        return ans;
    }
};
