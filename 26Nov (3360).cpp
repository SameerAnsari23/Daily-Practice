class Solution {
public:
    bool canAliceWin(int n) {
        bool flag = false;
        int i = 0;
        while(10 - i > 0 && n >= 10 - i) {
                n = n - (10 - i);
                flag = !flag;
                i++;
        }
        return flag;
    }
};
