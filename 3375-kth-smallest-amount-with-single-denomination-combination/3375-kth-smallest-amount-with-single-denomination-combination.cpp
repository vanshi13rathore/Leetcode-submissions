class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto count = [&](long long x) {
            long long ans = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                int cnt = 0;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        cnt++;
                        l = l / gcd(l, (long long)coins[i]) * coins[i];

                        if (l > x) break;
                    }
                }

                if (l > x) continue;

                if (cnt & 1)
                    ans += x / l;
                else
                    ans -= x / l;
            }

            return ans;
        };

        long long lo = 1;
        long long hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};