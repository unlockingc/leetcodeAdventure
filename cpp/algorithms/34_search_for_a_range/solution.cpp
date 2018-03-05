class Solution {
public:
    vector<int> find(vector<int>& nums, int start, int end, int target) {
        vector<int> res = {-1, -1};
        vector<int> temp;
        if (start >= end) {
            return res;
        }
        if (target < nums[start] || target > nums[end-1]) {
            return res;
        }
        if (nums[start] == nums[end-1] || (end-start) == 1) {
            if (nums[start] == target) {
                res[0] = start;
                res[1] = end-1;
            }
            return res;
        }
        int mid = (end + start) / 2;
        temp = find(nums, start, mid, target);
        if (res[0] != -1 && temp[0] != -1)
            res[0] = min(res[0], temp[0]);
        else {
            res[0] = max(res[0], temp[0]);
        }
        res[1] = max(res[1], temp[1]);
        temp = find(nums, mid, end, target);
        if (res[0] != -1 && temp[0] != -1)
            res[0] = min(res[0], temp[0]);
        else {
            res[0] = max(res[0], temp[0]);
        }
        res[1] = max(res[1], temp[1]);
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int len = nums.size();
        res = find(nums, 0, len, target);
        return res;
    }
};
