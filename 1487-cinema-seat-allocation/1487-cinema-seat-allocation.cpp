class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Store reserved seats as a bitmask for each row
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];
            mp[row] |= (1 << s);
        }

        // Every row starts with 2 possible groups
        long long ans = 2LL * n;

        for (auto &[row, mask] : mp) {
            // This row was counted as 2, so remove it first
            ans -= 2;

            // Left block: 2,3,4,5
            bool left = !(mask & (1 << 2)) &&
                        !(mask & (1 << 3)) &&
                        !(mask & (1 << 4)) &&
                        !(mask & (1 << 5));

            // Right block: 6,7,8,9
            bool right = !(mask & (1 << 6)) &&
                         !(mask & (1 << 7)) &&
                         !(mask & (1 << 8)) &&
                         !(mask & (1 << 9));

            if (left && right)
                ans += 2;
            else if (left || right)
                ans += 1;
            else {
                // Middle block: 4,5,6,7
                bool middle = !(mask & (1 << 4)) &&
                              !(mask & (1 << 5)) &&
                              !(mask & (1 << 6)) &&
                              !(mask & (1 << 7));

                if (middle)
                    ans += 1;
            }
        }

        return ans;
    }
};