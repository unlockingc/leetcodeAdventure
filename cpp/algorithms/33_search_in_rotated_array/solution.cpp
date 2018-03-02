class Solution {
public:
    int find(vector<int>& nums, int start, int end, int target) {
        if (nums[start] == target) {
            return start;
        }
        if (end-start <= 1) {
            return -1;
        }
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        } 
        if (nums[mid] >= nums[0]) {                // increasing
            if (nums[mid] < target) {
                return find(nums, mid+1, end, target);
            } else if (target < nums[0]) {
                return find(nums, mid+1, end, target);
            } else {
                return find(nums, start, mid, target);
            }
        } else {                                   // decreasing
            if (nums[mid] > target) {
                return find(nums, start, mid, target);
            } else if (target > nums[0]) {
                return find(nums, start, mid, target);
            } else {
                return find(nums, mid+1, end, target);
            }
        }
    }
    
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return -1;
        int res = find(nums, 0, len, target);
        return res;
    }
};