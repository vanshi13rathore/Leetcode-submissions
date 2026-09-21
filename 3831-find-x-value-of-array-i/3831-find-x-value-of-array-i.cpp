class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
                vector<long long> ans(k, 0);

        // dp[r] = number of subarrays ending at the previous position
        // whose product % k == r
        vector<long long> dp(k, 0);

        for (int x : nums) {
            vector<long long> ndp(k, 0);

            // Start a new subarray with just x
            ndp[x % k]++;

            // Extend every previous subarray
            for (int r = 0; r < k; r++) {
                if (dp[r]) {
                    int nr = (long long)r * (x % k) % k;
                    ndp[nr] += dp[r];
                }
            }

            dp = ndp;

            // Every non-empty subarray corresponds to exactly
            // one choice of prefix and suffix.
            for (int r = 0; r < k; r++)
                ans[r] += dp[r];
        }

        return ans;

    }
};