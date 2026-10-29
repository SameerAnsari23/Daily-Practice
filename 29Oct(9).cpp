class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;
        int n = x;
        int revnum = 0;
        while(n != 0){
            int digit = n % 10;
            if ((revnum > INT_MAX / 10) || (revnum < INT_MIN / 10))return 0;
            revnum = revnum*10 + digit;
            n = n / 10;
        }
        if(revnum == x)return true;
        else
        return false;
    }
};
