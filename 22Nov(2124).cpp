class Solution {
public:
    bool checkString(string s) {\
        bool flag = true;
        for (int i = 0; i < s.length(); i++) {
            if (!flag && s[i] == 'a') return false;
            if (s[i] == 'b') flag = false;
        }
        return true;
    }
};
