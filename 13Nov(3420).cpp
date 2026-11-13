class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long cnt = 0, cost = 0;
        int r = nums.size()-1;
        deque<int> block;

        for (int l = r; l >= 0; l--) {
            while (!block.empty() && nums[block.front()] <= nums[l]) {
                int j = block.front();
                block.pop_front();
                int e = r+1;
                if (!block.empty()) e = block.front();
                long long gap = nums[l] - nums[j];
                cost += gap*(e-j);
            }
            block.push_front(l);

            while (cost > k) {
                cost -= nums[block.back()] - nums[r];
                if (block.back() == r) block.pop_back();
                r--;
            }
            cnt += r-l+1;
        }
        return cnt;
    }
};
