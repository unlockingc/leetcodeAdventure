class Solution {
public:
    void dfs(vector<int>& candidates, vector<int>& temp, vector<vector<int>>& res, int target, int begin) {
        if (target == 0) {
            if (find(res.begin(), res.end(), temp) == res.end())
                res.push_back(temp);
            return;
        }

        int len = candidates.size();
        for (int i = begin; i < len; i++) {
            if (candidates[i] > target)
                return;
            temp.push_back(candidates[i]);
            dfs(candidates, temp, res, target-candidates[i], i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());
        dfs(candidates, temp, res, target, 0);
        return res;
    }
};
