class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();
        if (len2 > len1)
            return -1;
        int l = len1-len2;
        for (int i = 0; i <= l; i++) {
            // cout << haystack.substr(i,len2) << " " << needle << endl;
            if (haystack.substr(i,len2) == needle)
                return i;
        }
        return -1;
    }
};
