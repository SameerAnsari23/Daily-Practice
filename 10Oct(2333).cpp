class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int>diff(1e5+1, 0);
        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff[d]++;
        }
        int k = k1+k2;
        for (int i = 1e5; i > 0 && k > 0; i--) {
            int cnt = min(diff[i], k);
            diff[i] -= cnt;
            diff[i-1] += cnt;
            k -= cnt;
        }

        long long sum = 0;
        for (long long i = 1; i <= 1e5; i++) {
            sum += (diff[i]*i*i);
        }
        return sum;
    }
}; 
