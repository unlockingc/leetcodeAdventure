class Solution {
public:
    string commonPrefix(string s1, string s2) {
        string prefix = "";
        int length1 = s1.length();
        int length2 = s2.length();
        int length = min(length1, length2);
        for (int i = 0; i < length; i++) {
            if (s1[i] == s2[i])
                prefix += s1[i];
            else
                break;
        }
        return prefix;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int length = strs.size();
        if (length < 1)
            return "";
        else {
            string prefix = strs[0];
            for (int i = 1; i < strs.size(); i++) {
                prefix = commonPrefix(prefix, strs[i]);
            }
            return prefix;
        }
    }
};
