class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());
        vector<vector<vector<int>>> res(target+1, vector<vector<int>>());

        if (candidates.empty() || target < candidates[0])
            return res[target];

        int len = candidates.size();
        for (int i = 0; i < len; i++) {
            if (candidates[i] <= target) {
                res[candidates[i]].push_back(vector<int> {candidates[i]});
            } else {
                break;
            }
        }

        int begin, last, l;

        vector<int> temp;

        for (int i = candidates[0]+1; i <= target; i++) {
            begin = candidates[0];
            last = i-begin;
            while(begin <= last) {
                if (!res[last].empty() && !res[begin].empty()) {
                    for (int j = 0; j < res[begin].size(); j++) {
                        for (int k = 0; k < res[last].size(); k++) {
                            temp = res[begin][j];
                            temp.insert(temp.end(), res[last][k].begin(), res[last][k].end());
                            sort(temp.begin(), temp.end());
                            for (l = 0; l < res[i].size(); l++)
                                if (res[i][l] == temp)
                                    break;
                            if (l == res[i].size())
                                res[i].push_back(temp);
                        }
                    }
                }
                begin ++;
                last --;
            }
        }
        return res[target];
    }
};
