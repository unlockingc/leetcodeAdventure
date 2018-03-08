class Solution {
public:
    bool check(int i, int j, vector<vector<int>>& hasQueen) {
        int n = hasQueen.size();

        for (int k = 0; k < i; k++) {
            if (hasQueen[k][j] == 1) {
                return false;
            }
        }
        int k,l;
        k = i;
        l = j;

        while (k >= 0 && l < n) {
            if (hasQueen[k][l] == 1)
                return false;
            k --;
            l ++;
        }
        k = i;
        l = j;
        while (k >= 0 && l >= 0) {
            if (hasQueen[k][l] == 1)
                return false;
            k --;
            l --;
        }
        return true;
    }
    void placeQueen(int i, int n, vector<vector<string>>& res, vector<string>& state, vector<vector<int>>& hasQueen) {
        if (i == n) {
            res.push_back(state);
            return;
        }
        string temp(n, '.');
        for (int j = 0; j < n; j++) {
            if (check(i, j, hasQueen)) {
                hasQueen[i][j] = 1;
                temp[j] = 'Q';
                state.push_back(temp);
                placeQueen(i+1, n, res, state, hasQueen);
                state.pop_back();
                temp[j] = '.';
                hasQueen[i][j] = 0;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> hasQueen(n, vector<int>(n, 0));
        vector<string> state;
        vector<vector<string>> res;
        placeQueen(0, n, res, state, hasQueen);
        return res;
    }
};
