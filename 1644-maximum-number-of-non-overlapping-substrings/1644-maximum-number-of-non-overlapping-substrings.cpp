class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> L(26, n), R(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            L[c] = min(L[c], i);
            R[c] = i;
        }

        vector<pair<int,int>> valid;

        for (int c = 0; c < 26; c++) {
            if (R[c] == -1) continue;

            int l = L[c], r = R[c];
            bool ok = true;

            for (int i = l; i <= r; i++) {
                int x = s[i] - 'a';

                if (L[x] < l) {
                    ok = false;
                    break;
                }

                r = max(r, R[x]);
            }

            if (ok) valid.push_back({l, r});
        }

        sort(valid.begin(), valid.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int end = -1;

        for (auto [l, r] : valid) {
            if (l > end) {
                ans.push_back(s.substr(l, r - l + 1));
                end = r;
            }
        }

        return ans;
    }
};