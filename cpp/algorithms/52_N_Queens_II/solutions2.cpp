class Solution {
public:
    void update(int row, int col, vector<vector<int>>& hasQueen, int val) {
        int n = hasQueen[0].size();

        for (int i = row + 1, left = col-1, right = col+1; i < n; i++) {
            hasQueen[i][col] += val;

            if (left >= 0)
                hasQueen[i][left--] += val;

            if (right < n)
                hasQueen[i][right++] += val;

        }
    }
    void placeQueen(int i, int n, int& num, vector<vector<int>>& hasQueen) {
        if (i == n) {
            num += 1;
            return;
        }

        for (int j = 0; j < n; j++) {
            if (hasQueen[i][j] == 0) {
                update(i, j, hasQueen, 1);
                placeQueen(i+1, n, num, hasQueen);
                update(i, j, hasQueen, -1);
            }
        }
        return;
    }
    int totalNQueens(int n) {
        int num = 0;
        vector<vector<int>> hasQueen(n, vector<int>(n, 0));
        placeQueen(0, n, num, hasQueen);
        return num;
    }

};
