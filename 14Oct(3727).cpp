class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            sq[i] = static_cast<long long>(nums[i]) * nums[i];
        }
        sort(sq.begin(), sq.end());

        long long ans = 0;
        for (int i = 0; i < nums.size() / 2; i++) {
            ans -= sq[i];
        }
        for (int i = nums.size() / 2; i < nums.size(); i++) {
            ans += sq[i];
        }
        return ans;
    }
};
