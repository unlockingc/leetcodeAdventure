class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return vector<int>();
        int end_m = matrix.size()-1;
        int end_n = matrix[0].size()-1;

        int begin = 0;
        vector<int> res;
        int i, j;
        while (begin < end_m && begin < end_n) {
            i = begin;
            j = begin;

            while (j < end_n) {
                res.push_back(matrix[i][j]);
                j ++;
            }
            while (i < end_m) {
                res.push_back(matrix[i][j]);
                i ++;
            }
            while (j > begin) {
                res.push_back(matrix[i][j]);
                j --;
            }
            while (i > begin) {
                res.push_back(matrix[i][j]);
                i --;
            }
            begin ++;
            end_n --;
            end_m --;
        }
        if (begin == end_n && begin < end_m) {
            i = begin;
            j = begin;
            while (i <= end_m) {
                res.push_back(matrix[i][j]);
                i ++;
            }
        } else if (begin == end_m && begin < end_n) {
            i = begin;
            j = begin;
            while (j <= end_n) {
                res.push_back(matrix[i][j]);
                j ++;
            }
        } else if (begin == end_m && begin == end_n) {
            res.push_back(matrix[begin][begin]);
        }
        return res;
    }
};
