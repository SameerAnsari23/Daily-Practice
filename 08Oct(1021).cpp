class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        /*bool open = false;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (!open && s[i] == '(') {
                open = true;
            }
            else {
                if (s[i] == ')' && cnt > 0) {
                    cnt--;
                    ans.push_back(s[i]);
                }
                else if (s[i] == '(') {
                    cnt++;
                    ans.push_back(s[i]);
                }
                else if (s[i] == ')' && cnt == 0) open = false;
            }
        }*/



        // good way to write code 
        int open = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                if (open > 0) ans.push_back(s[i]);
                open++;
            }
            else {
                open--;
                if (open > 0) ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
