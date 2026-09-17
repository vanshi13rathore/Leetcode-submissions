class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), ans = INT_MAX;
        vector<int> best(n, INT_MAX);

        int left = 0, sum = 0, len = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target)
                sum -= arr[left++];

            if (sum == target) {
                int cur = right - left + 1;

                if (left > 0 && best[left - 1] != INT_MAX)
                    ans = min(ans, cur + best[left - 1]);

                len = min(len, cur);
            }

            best[right] = len;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};