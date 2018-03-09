class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        int paths[m][n] = {0};
        paths[m-1][n-1] = grid[m-1][n-1];
        for (int i = m-2; i >= 0; i--) {
            paths[i][n-1] = grid[i][n-1] + paths[i+1][n-1];
        }
        for (int i = n-2; i >= 0; i--) {
            paths[m-1][i] = grid[m-1][i] + paths[m-1][i+1];
        }
        for (int i = n-2; i >= 0; i--) {
            for (int j = m-2; j >= 0; j--)
                paths[j][i] = grid[j][i] + min(paths[j+1][i], paths[j][i+1]);
        }
        return paths[0][0];
    }
};
