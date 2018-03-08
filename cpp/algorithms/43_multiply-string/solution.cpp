class Solution {
        
public:
    string multiply(string num1, string num2) {
        string ret = num1;
        string sum(num1.size() + num2.size(), '0');
        
        for( int i = 0; i < num1.length(); i++ )
        {
            for( int j = 0; j < num2.length(); j++ )
            {
                int temp = (int)((num2[j]-'0')*(num1[i] - '0'));
                int where = sum.length() - ( num1.length() + num2.length()  - i - j  - 2) - 1;
                
                sum[where] += temp%10;
                sum[where - 1] += temp/10;
                
                // cout << "i: " << i <<  "j: " << j << endl;
                // cout << "temp: " << temp << endl;
                // cout << "sum[where]: " << sum[where] << "\t" << (int)(sum[where]) << endl;
                // cout << "sum[where - 1]: " << sum[where - 1] << "\t" << (int)(sum[where - 1]) << endl;
                // cout << "=======================================" << endl;
                
                if( sum[where] > '9'  )
                {
                    sum[where - 1] += (sum[where] - '0')/10;
                    sum[where] = (sum[where] - '0')%10 + '0';
                }
                
                int overflow = where - 1;
                while( sum[overflow] > '9' )
                {
                    sum[overflow - 1] += (sum[overflow] - '0')/10;
                    sum[overflow] = (sum[overflow] - '0')%10 + '0';
                    overflow --;
                }
            }
        }
        
        //cout << "sum: " << sum << endl;
        
        size_t startpos = sum.find_first_not_of("0");
        if (string::npos != startpos) {
            return sum.substr(startpos);
        }
        
        return "0";
    }
};