class Solution {
public:
    int minInsertions(string s) {
        int open = 0, cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open += 2;
                if (open % 2 == 1) {
                    cnt++;
                    open--;
                }
            }
            else {
                open--;
                if (open < 0) {
                    cnt++;
                    open = 1;
                }
            }
        }
        return open + cnt;
    }
};
