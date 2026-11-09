class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int s = 0, p = 1, cnt = 0;
        for (int e = 0; e < nums.size(); e++) {
            p = p * nums[e];
            while (p >= k) {
                p /= nums[s];
                s++;
            }
            cnt += (e - s + 1);
        }
        return cnt;
    }
};
