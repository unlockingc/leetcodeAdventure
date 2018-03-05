class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<vector<int>>> res(target+1, vector<vector<int>>());
        res[0].push_back(vector<int>());

        vector<vector<int>> temp;
        for (auto c : candidates) {
            for (int j = c; j <= target; j++) {
                if (!res[j-c].empty()) {
                    temp = res[j-c];
                    for (auto &tmp : temp)
                        tmp.push_back(c);
                    res[j].insert(res[j].end(), temp.begin(), temp.end());
                }
            }
        }
        return res[target];
    }
};
