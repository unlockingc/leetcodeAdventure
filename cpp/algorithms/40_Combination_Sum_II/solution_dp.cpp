class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<vector<int>>> res(target+1, vector<vector<int>>());
        res[0].push_back(vector<int>());
        vector<int> exist;
        vector<int> old_exist;
        exist.push_back(0);

        vector<vector<int>> temp;
        for (auto c : candidates) {
            if (c > target)
                continue;
            old_exist = exist;
            int s;
            for (int i = old_exist.size()-1; i >= 0; i--) {
                s = old_exist[i];
                if ((c+s) > target) {
                    continue;
                } else {
                    temp = res[s];
                    for (auto &tmp : temp) {
                        tmp.push_back(c);
                        if (find(res[c+s].begin(), res[c+s].end(), tmp) == res[c+s].end())
                            res[c+s].push_back(tmp);
                    }
                    if (find(exist.begin(), exist.end(), c+s) == exist.end())
                        exist.push_back(c+s);
                    sort(exist.begin(), exist.end());
                }
            }
        }
        return res[target];
    }
};
