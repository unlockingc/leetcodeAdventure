class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        int i = 0, j = 0;
        int begini = -1;
        int beginj;
        while (i < m) {
            if (j < n && p[j] == '*') {
                begini = i;
                beginj = j++;
            } else if (j < n && (p[j] == s[i] || p[j] == '?')) {
                j ++;
                i ++;
            } else if (begini >= 0) {
                cout << "3" << endl;
                i = ++begini;
                j = beginj+1;
            } else {
                return false;
            }
        }
        while (j < n && p[j] == '*')
            j++;
        if (j < n)
            return false;
        return true;
    }
};
