class Solution {
    static const int MOD = 1'000'000'007;

    struct SegmentTree {
        int n;
        vector<long long> sum, sq, lazy;

        SegmentTree(int n) : n(n) {
            sum.assign(4 * n, 0);
            sq.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }

        void apply(int node, int l, int r, long long delta) {
            long long len = r - l + 1;

            // Update sum of values and sum of squares.
            sq[node] = (sq[node]
                + 2 * delta % MOD * sum[node] % MOD
                + delta * delta % MOD * len % MOD) % MOD;

            sum[node] = (sum[node] + delta * len) % MOD;
            lazy[node] = (lazy[node] + delta) % MOD;
        }

        void push(int node, int l, int r) {
            if (lazy[node] == 0 || l == r) return;

            int mid = l + (r - l) / 2;
            apply(node * 2, l, mid, lazy[node]);
            apply(node * 2 + 1, mid + 1, r, lazy[node]);

            lazy[node] = 0;
        }

        void update(int node, int l, int r,
                    int ql, int qr, long long delta) {
            if (qr < l || r < ql) return;

            if (ql <= l && r <= qr) {
                apply(node, l, r, delta);
                return;
            }

            push(node, l, r);

            int mid = l + (r - l) / 2;
            update(node * 2, l, mid, ql, qr, delta);
            update(node * 2 + 1, mid + 1, r, ql, qr, delta);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        }

        void update(int l, int r, long long delta) {
            if (l > r) return;
            update(1, 0, n - 1, l, r, delta);
        }

        long long getSquareSum() {
            return sq[1];
        }
    };

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        SegmentTree st(n);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            st.update(last[x] + 1, i, 1);

            ans = (ans + st.getSquareSum()) % MOD;

            last[x] = i;
        }

        return (int)ans;
    }
};
