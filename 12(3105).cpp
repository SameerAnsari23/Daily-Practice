class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, inc = 1, dec = 1;

        for (int i = 1; i < nums.size(); i++) {
            bool a = nums[i] < nums[i-1], d = nums[i] > nums[i-1];
            inc = a*inc + 1;
            dec = d*dec + 1;
            ans = max(ans, max(inc, dec));
        }

        return ans;
    }
};
