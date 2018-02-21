class Solution {
public:
    
    unordered_map<string, int> roman;
    string c[4][10]={
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}
    };
    
    Solution()
    {
        roman[""] = 0;
        for(int j = 0; j < 4; j++)
        {
            for( int i = 1; i < 10; i ++ )
            {
                roman[c[j][i]] = i * (int)(pow(10,j));
            }
        }
    }
    
    int romanToInt(string s) {

        
        int ret = 0;
        
        string stack = "",stackOld = "";
        
        for( int i = 0; i < s.length(); i++ )
        {
            stackOld = stack;
            stack += s[i];
            
            if( roman[stack] == 0 && stack != "" )
            {
                ret += roman[stackOld];
                printf( "%s has been detected: +%d, now: %d\n", stackOld.c_str(), roman[stackOld], ret );
                stackOld = "";
                stack = s[i];
            }
        }
        
        ret += roman[stack];
        
        return ret;
    }
};