class Solution {
public:
    int longestValidParentheses(string s) {
        
        vector<int> stack;
        const int a = s.length();
        int borderMap[a + 1];
        
        memset( borderMap, 0, sizeof(int)*(s.length() + 1));
        
        int temp = 0;
        int longest = 0;
        
        for( int i = 0; i < s.length(); i ++ )
        {
            
            if( s[i] == '(' )
            {
                stack.push_back(i);
            }
            else
            {
                if( stack.size() != 0 )
                {   
                    temp =  borderMap[stack.back() - 1 + 1] + ( i - stack.back() + 1 );
                    borderMap[i + 1] = max(borderMap[i + 1], temp);
                    longest = max(borderMap[i + 1], longest);
                    stack.pop_back();
                }
            }
        }
        
        return longest;
    }
};