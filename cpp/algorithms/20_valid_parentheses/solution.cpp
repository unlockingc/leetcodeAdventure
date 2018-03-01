class Solution {
public:
    bool isValid(string s) {
       stack<char> st;

        int length = s.length();
        char c;
        for (int i = 0; i < length; i++) {
            if ( s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else if ( st.empty() ){
                return false;
            } else {
                c = st.top();
                if ( (c == '(' && s[i] == ')') ||
                    (c == '[' && s[i] == ']') ||
                    (c == '{' && s[i] == '}') )
                    st.pop();
                else
                    return false;
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};
