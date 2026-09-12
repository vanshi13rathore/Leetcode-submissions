class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; i++) intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });

        vector<int> ends(n);
        for (int i = 0; i < n; i++) ends[i] = intervals[i][1];

        vector<pair<long long, vector<int>>> dp[5];
        for (int k = 0; k <= 4; k++) dp[k].resize(n + 1);

        for (int i = 1; i <= n; i++) {
            for (int k = 0; k <= 4; k++)
                dp[k][i] = dp[k][i - 1];

            int l = intervals[i-1][0], w = intervals[i-1][2], id = intervals[i-1][3];
            int p = lower_bound(ends.begin(), ends.end(), l) - ends.begin();

            for (int k = 1; k <= 4; k++) {
                auto cur = dp[k-1][p];
                cur.first += w;
                cur.second.push_back(id);
                sort(cur.second.begin(), cur.second.end());

                if (cur.first > dp[k][i].first ||
                    (cur.first == dp[k][i].first && cur.second < dp[k][i].second))
                    dp[k][i] = cur;
            }
        }

        auto ans = dp[0][n];
        for (int k = 1; k <= 4; k++)
            if (dp[k][n].first > ans.first ||
                (dp[k][n].first == ans.first && dp[k][n].second < ans.second))
                ans = dp[k][n];

        return ans.second;
    }
};