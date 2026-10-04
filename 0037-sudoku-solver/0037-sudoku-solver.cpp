class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char num) {

        // Check row
        for(int j = 0; j < 9; j++) {
            if(board[row][j] == num) {
                return false;
            }
        }

        // Check column
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == num) {
                return false;
            }
        }

        // Find 3x3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        // Check 3x3 box
        for(int i = startRow; i < startRow + 3; i++) {
            for(int j = startCol; j < startCol + 3; j++) {

                if(board[i][j] == num) {
                    return false;
                }
            }
        }

        return true;
    }


    bool solve(vector<vector<char>>& board) {

        // Find an empty cell
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {

                if(board[row][col] == '.') {

                    // Try 1 to 9
                    for(char num = '1'; num <= '9'; num++) {

                        if(isSafe(board, row, col, num)) {

                            // CHOOSE
                            board[row][col] = num;

                            // EXPLORE
                            if(solve(board)) {
                                return true;
                            }

                            // UNDO
                            board[row][col] = '.';
                        }
                    }

                    // No number worked
                    return false;
                }
            }
        }

        // No empty cells
        return true;
    }


    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};