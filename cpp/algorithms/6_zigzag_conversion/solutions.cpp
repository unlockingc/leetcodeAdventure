class Solution {
public:
    string convert(string s, int numRows) {
        int length = s.length();
        if (numRows == 1)
            return s;

        string ans = "";
        int period1 = 2 * numRows - 2;
        int period2 = 0;
        int state = 0;
        int loc;
        for (int i = 0; i < numRows; i++) {
            loc = i;
            state = 0;
            while(loc < length) {
                ans += s[loc];
                if (period2 == 0)
                    loc += period1;
                else if (period1 == 0)
                    loc += period2;
                else {
                    if (state == 0)
                        loc += period1;
                    else
                        loc += period2;
                    state = 1 - state;
                }
            }
            period1 -= 2;
            period2 += 2;
        }
        return ans;
    }
};
