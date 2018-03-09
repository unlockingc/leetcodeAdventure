class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        if (n == 0)
            return 0;

        int paths[m][n] = {0};
        int i, j;
        for (i = m-1; i >= 0; i--) {
            if (obstacleGrid[i][n-1] == 1) {
                break;
            }
            paths[i][n-1] = 1;
        }
        for (j = i; j >= 0; j--)
            paths[j][n-1] = 0;

        for (i = n-1; i >= 0; i--) {
            if (obstacleGrid[m-1][i] == 1)
                break;
            paths[m-1][i] = 1;
        }
        for (j = i; j >= 0; j--)
            paths[m-1][j] = 0;

        for (int i = n-2; i >= 0; i--) {
            for (int j = m-2; j >= 0; j--)
                paths[j][i] = obstacleGrid[j][i] == 0 ? paths[j+1][i] + paths[j][i+1] : 0;
        }
        return paths[0][0];
    }
};
