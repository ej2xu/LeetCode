class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      int row[9][9] = {}, col[9][9] = {}, block[9][9] = {};
      for (int i=0; i < 9; i++)
        for (int j=0; j < 9; j++)
          if (board[i][j] != '.') {
            char cur = board[i][j]-'1';
            if (row[i][cur]++ || col[j][cur]++ || block[3*(i/3)+j/3][cur]++)
              return false;
          }
      return true;
    }
};
