class Solution {
public:

    bool dfs(vector<vector<char>>& grid, int i, int j, int balance,
             vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        // Balance can never become negative
        if(balance < 0)
            return false;

        // Reached outside the grid
        if(i >= m || j >= n)
            return false;

        // Update balance using current cell
        if(grid[i][j] == '(')
            balance++;
        else
            balance--;

        // Invalid balance
        if(balance < 0)
            return false;

        // Reached destination
        if(i == m - 1 && j == n - 1)
            return balance == 0;

        // Already calculated
        if(dp[i][j][balance] != -1)
            return dp[i][j][balance];

        // Move down OR right
        bool down = dfs(grid, i + 1, j, balance, dp);
        bool right = dfs(grid, i, j + 1, balance, dp);

        return dp[i][j][balance] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Path length must be even
        if((m + n - 1) % 2 != 0)
            return false;

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n, vector<int>(m + n, -1))
        );

        return dfs(grid, 0, 0, 0, dp);
    }
};