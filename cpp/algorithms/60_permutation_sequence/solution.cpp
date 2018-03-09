class Solution {
public:
    bool nextPermute(vector<int>& num) {
        int len = num.size();
        int j;
        for (int i = len-1; i > 0; i--) {
            if (num[i] > num[i-1]) {
                sort(num.begin()+i, num.end());
                j = i;
                while (num[j] < num[i-1])
                    j ++;
                swap(num[i-1], num[j]);
                return true;
            }
        }
        return false;
    }
    string getPermutation(int n, int k) {
        vector<int> num(n,0);
        for (int i = 0; i < n; i++)
            num[i] = i+1;
        int index = 1;
        while (index < k && nextPermute(num)) {
            index ++;
        }
        string res = "";
        for (int i = 0; i < n; i++) {
            res += (char)('0'+num[i]);
        }
        return res;
    }
};
