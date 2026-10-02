class Solution {
public:

    bool solve(int row, int col, int index,
               vector<vector<char>>& board, string& word) {

        // All characters matched
        if(index == word.size())
            return true;

        // Out of bounds
        if(row < 0 || row >= board.size() ||
           col < 0 || col >= board[0].size())
            return false;

        // Wrong character
        if(board[row][col] != word[index])
            return false;

        // Mark current cell as visited
        char original = board[row][col];
        board[row][col] = '#';

        // Try 4 directions
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int d = 0; d < 4; d++) {

            int newRow = row + dr[d];
            int newCol = col + dc[d];

            if(solve(newRow, newCol, index + 1, board, word))
                return true;
        }

        // Backtrack
        board[row][col] = original;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        // Try every cell as a starting point
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {

                if(board[row][col] == word[0]) {

                    if(solve(row, col, 0, board, word))
                        return true;
                }
            }
        }

        return false;
    }
};