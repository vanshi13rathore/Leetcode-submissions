class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            // Find maximum element in middle column
            int maxRow = 0;

            for(int i = 1; i < m; i++) {
                if(mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            // Check left and right neighbours
            int left = (mid == 0) ? -1 : mat[maxRow][mid - 1];
            int right = (mid == n - 1) ? -1 : mat[maxRow][mid + 1];

            // Current element is a peak
            if(mat[maxRow][mid] > left &&
               mat[maxRow][mid] > right) {

                return {maxRow, mid};
            }

            // Bigger element is on the left
            if(left > mat[maxRow][mid]) {
                high = mid - 1;
            }
            else {
                // Bigger element is on the right
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};