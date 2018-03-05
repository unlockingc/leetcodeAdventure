class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int check[10];
        int len = board.size();

        for (int i = 0; i < len; i++) {
            for (int k = 0; k < 10; k++)
                check[k] = 0;
            for (int j = 0; j < len; j++) {
                if (board[i][j] != '.') {
                    if (check[(board[i][j]-'0')] != 1) {
                        check[(board[i][j]-'0')] = 1;
                    } else {
                        return false;
                    }

                }
            }
            for (int k = 0; k < 10; k++)
                check[k] = 0;
            for (int j = 0; j < len; j++) {
                if (board[j][i] != '.') {
                    if (check[(board[j][i]-'0')] != 1) {
                        check[(board[j][i]-'0')] = 1;
                    } else {
                        return false;
                    }
                }
            }
            if (i % 3 == 2) {
                for (int j = 2; j < 9; j += 3) {
                    cout << "j: " << j << endl;
                    for (int k = 0; k < 10; k++)
                        check[k] = 0;
                    for (int ii = i-2; ii <= i; ii++) {
                        for (int jj = j-2; jj <= j; jj++) {
                            if (board[ii][jj] != '.') {
                                if (check[(board[ii][jj]-'0')] != 1) {
                                    check[(board[ii][jj]-'0')] = 1;
                                } else {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
