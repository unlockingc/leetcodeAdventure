class Solution {
public:
    string intToRoman(int num) {
        char* c[4][10]={
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}
        };
        
        string ret = "";
        
        //for speed
        int temp = 1000;
        
        for( int i = 3; i >=0; i--,temp/=10 )
        {
            //ret.append( c[i][num/(int)(pow(10,i))] );
            //num = num % (int)(pow(10,i));
            
            ret += c[i][num/temp];
            num = num % temp;
        }
        
        return ret;
    }
};