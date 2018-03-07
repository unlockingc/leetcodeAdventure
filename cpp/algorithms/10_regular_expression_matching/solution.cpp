class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        int i = 0, j = 0;

        vector<int> begin(n, -1);
        int back;
        while (i < m) {
            if (j < n && j+1 < n && p[j+1] == '*') {
                if (p[j] == '.' || p[j] == s[i]) {
                    begin[j] = i;
                } else {
                    begin[j] = -1;
                }
                back = j+2;
                while (back < n && back+1 < n && p[back] == p[j] && p[back+1] == '*')
                    back += 2;
                j = back;
            } else if (j < n && (p[j] == '.' || p[j] == s[i])) {
                i ++;
                j ++;
            } else {
                back = j-1;
                while(back >= 0 && begin[back] < 0) {
                    back --;
                }
                if (back < 0)
                    return false;
                else {
                    begin[back] ++;
                    i = begin[back];
                    j = back;
                }
            }
        }
        while (j < n && j+1 < n && p[j+1] == '*')
            j += 2;
        if (j < n)
            return false;
        else
            return true;
    }
};
