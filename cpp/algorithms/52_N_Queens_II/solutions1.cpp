class Solution {
public:
    void placeQueen(int i, int n, int& num, int cols[], int main[], int anti[]) {
        if (i == n) {
            num += 1;
            return;
        }

        int col, midx, aidx;
        for (int j = 0; j < n; j++) {
            col = j;
            midx = j - i + n - 1;
            aidx = i + j;
            if (cols[col] == 0 && main[midx] == 0 && anti[aidx] == 0) {
                cols[col] = 1;
                main[midx] = 1;
                anti[aidx] = 1;
                placeQueen(i+1, n, num, cols, main, anti);
                cols[col] = 0;
                main[midx] = 0;
                anti[aidx] = 0;
            }
        }
        return;
    }
    int totalNQueens(int n) {
        int num = 0;
        int cols[n] = {0};
        int main[2*n-1] = {0};
        int anti[2*n-1] = {0};
        placeQueen(0, n, num, cols, main, anti);
        return num;
    }

};
