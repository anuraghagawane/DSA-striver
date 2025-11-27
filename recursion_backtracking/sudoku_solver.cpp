class Solution {
    unordered_map<char, unordered_set<char>> row;
    unordered_map<char, unordered_set<char>> col;
    unordered_map<char, unordered_set<char>> grid;
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == num) return false;
            if(board[i][col] == num) return false;
        }

        int gridRowStart = (row / 3) * 3;
        int gridColStart = (col / 3) * 3;

        for(int i = gridRowStart; i < gridRowStart+3; i++) {
            for(int j = gridColStart; j < gridColStart+3; j++) {
                if(board[i][j] == num) return false;
            }   
        }

        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.') continue;
                for(char c = '1'; c <= '9'; c++){
                    if(isValid(board, i, j, c)){
                        board[i][j] = c;
                        if(solve(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};