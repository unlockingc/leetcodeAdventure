class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<int> temp(2*n,0);
        vector<string> s;
        string t = "";
        for (int i = n; i < 2*n; i++) {
            temp[i] = 1;
        }

        int nums_one = 0;
        int nums_zero = 0;
        bool flag = true;
        while (flag) {
            t = "";
            for (int i = 0; i < 2*n; i++) {
                if (temp[i] == 0)
                    t += '(';
                else
                    t += ')';
            }
            s.push_back(t);

            flag = false;
            nums_one = 1;
            nums_zero = 0;
            for (int i = 2*n-2; i >= 0; i--) {
                if (temp[i] == 0)
                    nums_zero += 1;
                else
                    nums_one += 1;
                if (temp[i] == 0 && temp[i+1] == 1 && (nums_one - nums_zero) >= 1 ) {
                    temp[i] = 1;
                    for (int j = i+1; j < 2*n; j++) {
                        if (nums_zero > 0) {
                            temp[j] = 0;
                            nums_zero --;
                        } else {
                            temp[j] = 1;
                        }
                    }
                    flag = true;
                    break;
                }
            }
        }

        return s;
    }
};
