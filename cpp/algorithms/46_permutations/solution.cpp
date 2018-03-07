class Solution {
public:
    vector<vector<int>> recursive(vector<int>& nums, vector<int>& flag) {
        vector<vector<int>> temp_res, res;
        for (int i = 0; i < flag.size(); i++)
            if (flag[i] == 0) {
                flag[i] = 1;
                temp_res = recursive(nums, flag);
                if (temp_res.size() == 0)
                    res.push_back(vector<int>{nums[i]});
                for (int j = 0; j < temp_res.size(); j++) {
                    temp_res[j].push_back(nums[i]);
                    res.push_back(temp_res[j]);
                }
                flag[i] = 0;
            }
        return res;

    }

    bool nextPermute(vector<int>& num) {
        int len = num.size();
        int j;
        for (int i = len-1; i > 0; i--) {
            if (num[i] > num[i-1]) {
                sort(num.begin()+i, num.end());
                j = i;
                while (num[j] < num[i-1])
                    j ++;
                swap(num[i-1], num[j]);
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> num(nums);
        sort(num.begin(), num.end());

        vector<vector<int>> res;
        do {
            res.push_back(num);
        } while (nextPermute(num));
        return res;
    }
};
