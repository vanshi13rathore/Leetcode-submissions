class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<pair<int, int>> dirs = {
            {-1, 0}, {1, 0}, {0,-1}, {0,1}
            
        };

        for(int r=0; r<m; r++) {
            for(int c=0; c<n; c++) {
                if(grid[r][c] == 0) {
                    continue;
                }

                long long sum = 0;
                stack<pair<int, int>> st;
                st.push({r, c});

                sum += grid[r][c];
                grid[r][c] = 0;

                while(!st.empty()) {
                    auto [x,y] = st.top();
                    st.pop();

                    for(auto& d : dirs) {
                        int nx = x+d.first;
                        int ny = y+d.second;

                        if(nx >= 0 && nx < m && 
                            ny >= 0 && ny < n && 
                            grid[nx][ny] > 0) {

                                sum += grid[nx][ny];
                                grid[nx][ny] = 0;
                                st.push({nx, ny});
                            }
                    }
                }

                if(sum % k == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};