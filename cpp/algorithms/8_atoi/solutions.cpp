class Solution {
public:
    int myAtoi(string str) {
       int res = 0;
        str.erase(str.begin(), find_if(str.begin(), str.end(), [](int ch) {
            return !isspace(ch);
        }));
        int length = str.length();
        if (length == 0)
            return res;

        int sign = 0, begin = 0;
        if (str[0] == '-') {
            sign = 1;
            begin = 1;
        } else if (str[0] == '+') {
            begin = 1;
        }

        int check;
        for (int i = begin; i < length; i++) {
            check = res;
            if (str[i] >= '0' && str[i] <= '9')
                res = res * 10 + (str[i] - '0');
            else
                break;
            if (check != (res - (str[i] - '0')) / 10 || res < 0) {
                check = -1;
                break;
            }
        }
        if (sign) {
            if (check == -1)
                return -2147483648;
            return 0-res;
        } else {
            if (check == -1)
                return 2147483647;
            return res;
        }
    }
};
