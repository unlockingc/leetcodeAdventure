class Solution {
public:
    bool nextPermute(vector<int>& num) {
        int len = num.size();
        int j;
        for (int i = len-1; i > 0; i--) {
            if (num[i] > num[i-1]) {
                sort(num.begin()+i, num.end());
                j = i;
                while (num[j] <= num[i-1])
                    j ++;
                swap(num[i-1], num[j]);
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> num(nums);
        sort(num.begin(), num.end());

        vector<vector<int>> res;
        do {
            res.push_back(num);
        } while (nextPermute(num));
        return res;
    }
};
