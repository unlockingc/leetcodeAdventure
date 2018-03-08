class Solution {
        
public:
    string multiply(string num1, string num2) {
        string ret = num1;
        string sum(num1.size() + num2.size(), '0');
        
        for( int i = 0; i < num1.length(); i++ )
        {
            for( int j = 0; j < num2.length(); j++ )
            {
                int temp = num2[j];
                int where = sum.length() - ( num1.length() + num2.length()  - i - j  - 2) - 1;
                while( temp != '0' )
                {
                    sum[where] += (num1[i] - '0');
                    temp --;
                    
                    int overflow = where;
                    while( sum[overflow] > '9' )
                    {
                        sum[overflow - 1] ++;
                        sum[overflow] = ( sum[overflow] - ('9' + 1)) + '0';
                        overflow --;
                    }
                }
            }
        }
        
        size_t startpos = sum.find_first_not_of("0");
        if (string::npos != startpos) {
            return sum.substr(startpos);
        }
        return "0";
    }
};