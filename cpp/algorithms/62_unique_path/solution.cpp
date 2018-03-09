class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0)
            return 0;
        int paths[m][n] = {0};
        for (int i = 0; i < m; i++) {
            paths[i][n-1] = 1;
        }
        for (int i = 0; i < n; i++) {
            paths[m-1][i] = 1;
        }
        for (int i = n-2; i >= 0; i--) {
            for (int j = m-2; j >= 0; j--)
                paths[j][i] = paths[j+1][i] + paths[j][i+1];
        }
        return paths[0][0];
    }
};
