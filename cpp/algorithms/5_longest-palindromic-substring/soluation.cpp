class Solution {
public:
    int p[1000][1000];

    string longestPalindrome(string s) {

        for( int i = 0; i < 1000; i++ )
        {
            memset( p, 0, 1000* sizeof(int));
        }

        int start = 0, length = 1;

        for( int i = 0; i < s.length(); i ++ )
        {
            for( int j = 0; j < s.length(); j ++)
            {
                if(j + i > s.length() - 1)
                    continue;

                if( i == 0 )
                {
                    p[j][j+i] = 1;
                    continue;
                }

                if( i == 1 && s[j] == s[j + i])
                {
                    start = j;
                    length = i + 1;

                    p[j][j + i] = 1;
                    continue;
                }

                if( p[j + 1][j + i -1] == 1 && s[j] == s[j + i] )
                {
                    start = j;
                    length = i + 1;
                    p[j][j + i] = 1;
                }
            }
        }

        return s.substr(start,length);

    }
};
