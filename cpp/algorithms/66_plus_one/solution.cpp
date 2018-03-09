class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int temp, t = 1;
        for (int i = n-1; i >= 0; i--) {
            if (digits[i] + t < 10) {
                digits[i] += t;
                return digits;
            } else {
                temp = digits[i] + t;
                digits[i] = temp % 10;
                t = temp / 10;
            }
        }
        digits.insert(digits.begin(), 1, t);
        return digits;
    }
};
