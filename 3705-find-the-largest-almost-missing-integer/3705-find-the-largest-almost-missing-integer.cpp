class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> count(51, 0);

        // Count in how many k-sized subarrays each number appears
        for (int i = 0; i + k <= n; i++) {
            vector<bool> seen(51, false);

            for (int j = i; j < i + k; j++) {
                seen[nums[j]] = true;
            }

            for (int x = 0; x <= 50; x++) {
                if (seen[x])
                    count[x]++;
            }
        }

        // Find the largest number appearing in exactly one subarray
        for (int x = 50; x >= 0; x--) {
            if (count[x] == 1)
                return x;
        }

        return -1;
    }
};