
class Solution {
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int size) : n(size), bit(size + 1, 0) {}

        // Point XOR update
        void add(int i, int value) {
            while (i <= n) {
                bit[i] ^= value;
                i += i & -i;
            }
        }

        // Prefix XOR query
        int query(int i) {
            int result = 0;

            while (i > 0) {
                result ^= bit[i];
                i -= i & -i;
            }

            return result;
        }

        // XOR-update an inclusive range [l, r]
        void rangeUpdate(int l, int r, int value) {
            add(l, value);
            add(r + 1, value);
        }
    };

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> depth(n, 0);
        vector<int> tin(n), tout(n);
        vector<int> baseMask(n, 0);

        // Iterative Euler Tour:
        // state 0 = enter node, state 1 = exit node
        int timer = 0;
        stack<tuple<int, int, int>> st;
        st.push({0, 0, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.top();
            st.pop();

            if (state == 1) {
                tout[u] = timer - 1;
                continue;
            }

            tin[u] = timer++;

            up[0][u] = p;

            for (int k = 1; k < LOG; k++) {
                up[k][u] = up[k - 1][up[k - 1][u]];
            }

            if (u == 0) {
                baseMask[u] = 1 << (s[u] - 'a');
            } else {
                baseMask[u] =
                    baseMask[p] ^ (1 << (s[u] - 'a'));
                depth[u] = depth[p] + 1;
            }

            st.push({u, p, 1});

            for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];

                if (v == p) {
                    continue;
                }

                st.push({v, u, 0});
            }
        }

        // LCA using binary lifting
        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) {
                swap(u, v);
            }

            int diff = depth[u] - depth[v];

            for (int k = 0; k < LOG; k++) {
                if (diff & (1 << k)) {
                    u = up[k][u];
                }
            }

            if (u == v) {
                return u;
            }

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }

            return up[0][u];
        };

        // Fenwick range updates use 1-based Euler positions.
        Fenwick fw(n + 1);

        auto currentPrefix = [&](int u) {
            return baseMask[u] ^ fw.query(tin[u] + 1);
        };

        vector<bool> answer;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int oldBit = 1 << (s[u] - 'a');
                int newBit = 1 << (c - 'a');
                int delta = oldBit ^ newBit;

                // Changing u affects prefix masks of
                // u and every descendant of u.
                fw.rangeUpdate(
                    tin[u] + 1,
                    tout[u] + 1,
                    delta
                );

                s[u] = c;
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int mask = currentPrefix(u)
                         ^ currentPrefix(v)
                         ^ (1 << (s[w] - 'a'));

                // True if zero or one bit is set.
                answer.push_back(
                    mask == 0 || (mask & (mask - 1)) == 0
                );
            }
        }

        return answer;
    }
};

