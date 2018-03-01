class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();

        int next;
        int last;
        int sum, temp;
        sum = nums[0] + nums[1] + nums[2];
        cout << sum << endl;
        for (int i = 0; i < size-1; i++) {
            next = i+1;
            last = size-1;
            while(next != last) {
                temp = nums[i] + nums[next] + nums[last];
                if (abs(sum-target) > abs(temp-target)) {
                    sum = temp;
                    cout << sum << endl;
                }
                if (temp < target) {
                    next ++;
                } else {
                    last --;
                }
            }
        }
        return sum;
    }
};
