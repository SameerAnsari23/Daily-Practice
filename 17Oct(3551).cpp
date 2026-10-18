class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            int rem = n % 10;
            sum += rem;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        vector<int>sorted(nums);
        sort(sorted.begin(), sorted.end(), [this](int n1, int n2) {
            int d1 = getSum(n1);
            int d2 = getSum(n2);
            if (d1 != d2) return d1 < d2;
            else return n1 < n2;
        });

        unordered_map<int, int>mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int expectedVal = sorted[i];
            int curVal = nums[i];
            if (expectedVal != curVal) {
                int idx = mp[expectedVal];
                swap(nums[i], nums[idx]);
                cnt++;
                mp[expectedVal] = i;
                mp[curVal] = idx;
            }
        }

        return cnt;
    }
};
