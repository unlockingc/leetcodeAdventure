class Solution {
public:
    
    int roman[100];
    
    int romanToInt(string s) {
        
        //unordered_map<char, int> roman({{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}});
        //unordered_map is fucking slow!!!!! we use array instead;
        roman['I']=1;
        roman['V']=5;
        roman['X']=10;
        roman['L']=50;
        roman['C']=100;
        roman['D']=500;
        roman['M']=1000;
        
        int ret = roman[s[s.length() - 1]];
        
        
        for( int i = 0; i < s.length() - 1; i++ )
        {

            if( roman[s[i]] < roman[s[i+1]])
            {
                ret -= roman[s[i]];
            }
            else
            {
                ret += roman[s[i]];
            }
        }
        
        return ret;
    }
};