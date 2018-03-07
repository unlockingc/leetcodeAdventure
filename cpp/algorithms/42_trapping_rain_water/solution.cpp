class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;

        if (j <= 1)
            return 0;

        int temp_max = 0;

        vector<int> left, right;
        while (i <= j) {
            if (height[i] > temp_max) {
                left.push_back(i);
                temp_max = height[i];
            }
            i ++;
        }
        temp_max = 0;
        while (j >= 0) {
            if (height[j] > temp_max) {
                right.push_back(j);
                temp_max = height[j];
            }
            j --;
        }

        int len2 = right.size();

        for (i = len2-1; i >= 0; i--) {
            left.push_back(right[i]);
        }

        int len1 = left.size();
        if (len1 <= 1)
            return 0;

        int res = 0;
        for (i = 0; i < len1-1; i++) {
            temp_max = min(height[left[i]], height[left[i+1]]);
            for (j = left[i]; j <= left[i+1]; j++) {
                res += max(0, temp_max-height[j]);
            }
        }

        return res;
    }
};
