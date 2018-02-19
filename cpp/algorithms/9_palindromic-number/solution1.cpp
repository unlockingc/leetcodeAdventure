class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 )
            return false;
        
        int count = 1;
        int temp = x;
        while(true)
        {
            temp = temp /10;
            if( temp < 1)
            {
                break;
            }
            count ++;
        }
        
        //cout << "count: " << count << endl;
        
        int nowLow = 0;
        int nowHigh = 0;
        int j = 0;
        
        for( int i = 1; i <= count/2; i ++)
        {
            j = count - i + 1;
            
            nowLow = x/pow(10,i -1) - ((int)(x/pow(10,i)))*10;
            nowHigh = x/pow(10,j -1) - ((int)(x/pow(10,j)))*10;
            
            //printf( "i: %d\t j: %d\nnowLow: %d\t nowHigh: %d\n",i,j,nowLow,nowHigh );
            
            if( nowLow != nowHigh )
            {
                return false;
            }
        }
        
        return true; 
    }
};