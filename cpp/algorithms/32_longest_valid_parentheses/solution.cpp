class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> st;
        int index = 0;
        int len = s.length();

        int ret = 0;
        int temp = 0;

        int start, t;
        bool flag = true;
        for(start = 0; start < len; start++)
            if (s[start] == '(')
                break;
        if (start >= (len-1))
            return 0;

        for(int i = start; i < len; i++) {
            if (s[i] == '(') {
                st.push_back(0);
                index += 1;
            }
            else {
                if (index == 0) {
                    continue;
                }
                temp = 2;
                while(index > 0 && st[index-1] != 0) {
                    temp += st[index-1];
                    st.pop_back();
                    index --;
                }
                if (index != 0) {
                    st.pop_back();
                    st.push_back(temp);
                    ret = max(ret, temp);
                } else {
                    ret = max(ret, temp-2);
                }
            }
        }

        int sum = 0;
        while(!st.empty()) {
            temp = st.back();
            if (temp == 0) {
                sum = 0;
            } else {
                sum += temp;
                ret = max(ret, sum);
            }
            st.pop_back();
        }
        return ret;
    }
};
