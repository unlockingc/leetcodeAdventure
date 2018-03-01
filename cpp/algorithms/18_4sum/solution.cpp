class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int next, last;
        int temp;
        vector<vector<int>> res;
        vector<int> ans(4);
        bool flag;
        for (int i = 0; i < size-3; i++) {
            for (int j = i+1; j < size-2; j++) {
                next = j+1;
                last = size-1;
                while(next != last) {
                    temp = nums[i] + nums[j] + nums[next] + nums[last];
                    if (temp == target) {
                        ans[0] = nums[i];
                        ans[1] = nums[j];
                        ans[2] = nums[next];
                        ans[3] = nums[last];
                        flag = true;
                        for (int k = 0; k < res.size(); k++)
                            if (res[k][0] == ans[0] && res[k][1] == ans[1] && res[k][2] == ans[2] && res[k][3] == ans[3]) {
                                flag = false;
                                break;
                            }
                        if (flag)
                            res.push_back(ans);
                        last --;
                    } else if (temp > target) {
                        last --;
                    } else {
                        next ++;
                    }
                }
            }
        }
        return res;
    }
};
