class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int end = n;
        for (int i = n-1; i >= 0; i--)
            if (s[i] != ' ') {
                end = i+1;
                break;
            }
        for (int i = end-1; i >= 0; i--) {
            if (s[i] == ' ')
                return end-i-1;
        }
        return end;
    }
};
