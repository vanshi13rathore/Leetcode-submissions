
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dirs = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        function<bool(int, int)> dfs = [&](int r, int c) -> bool {
            // Mark this land cell as visited
            grid[r][c] = 1;

            // A boundary cell means the island is not closed
            bool closed = (r > 0 && r < m - 1 &&
                           c > 0 && c < n - 1);

            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 0) {

                    bool neighborClosed = dfs(nr, nc);
                    closed = closed && neighborClosed;
                }
            }

            return closed;
        };

        int count = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    if (dfs(r, c)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
