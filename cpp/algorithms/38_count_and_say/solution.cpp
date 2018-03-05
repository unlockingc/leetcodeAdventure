class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";

        int start, len, index;
        string s;
        char cmp;
        for(int i = 2; i <= n; i++) {
            start = 0;
            index = start;
            len = cur.length();
            s = "";
            if (len == 1) {
                s = '1' + cur;
            }
            else {
                cmp = cur[0];
                start = 0;
                index = 1;
                while(index < len) {
                    if (cur[index] == cmp)
                        index += 1;
                    else {
                        s.push_back((index-start) + '0');
                        s.push_back(cmp);
                        cmp = cur[index];
                        start = index;
                    }
                }
                if (start < len) {
                    s.push_back((index-start) + '0');
                    s.push_back(cmp);
                }
            }
            cur = s;
        }
        return cur;
    }
};
