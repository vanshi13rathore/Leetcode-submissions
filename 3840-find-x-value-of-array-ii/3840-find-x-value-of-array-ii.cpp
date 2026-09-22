class Solution {
public:
    struct Node {
        int prod;
        array<int, 5> cnt{};

        Node() {
            prod = 1;
            cnt.fill(0);
        }
    };

    int k;
    vector<Node> seg;

    Node mergeNode(const Node& a, const Node& b) {
        Node res;

        res.prod = (long long)a.prod * b.prod % k;

        // Prefixes completely inside left part
        for (int r = 0; r < k; r++)
            res.cnt[r] += a.cnt[r];

        // Prefixes that continue into right part
        for (int r = 0; r < k; r++) {
            int nr = (long long)a.prod * r % k;
            res.cnt[nr] += b.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            int x = nums[l] % k;
            seg[node].prod = x;
            seg[node].cnt[x] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        seg[node] = mergeNode(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            int x = val % k;

            seg[node].prod = x;
            seg[node].cnt.fill(0);
            seg[node].cnt[x] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, val);
        else
            update(node * 2 + 1, mid + 1, r, pos, val);

        seg[node] = mergeNode(seg[node * 2], seg[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(node * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(node * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return mergeNode(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        this->k = k;

        int n = nums.size();

        seg.resize(4 * n);
        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            nums[index] = value;
            update(1, 0, n - 1, index, value);

            // Count all valid remaining prefixes
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};