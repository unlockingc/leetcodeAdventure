class Solution {
public:
    int divide(int dividend, int divisor) {
        
        bool ni = false;
        
        unsigned int dividend1 = dividend;
        unsigned int divisor1 = divisor;
        
        
        if( dividend < 0 )
        {
            ni = !ni;
            dividend1 =  0 - dividend;
        }
        
        if( divisor < 0 )
        {
            ni = !ni;
            divisor1 =  0 - divisor;
        }
        
        if( divisor == 0 )
        {
            return 2147483647;
        }
        
        
        if( dividend == -2147483648 && divisor == -1 )
        {
            return 2147483647;
        }
        
        unsigned int temp = 0;
        unsigned int grow = 0;
        int result = 0;
        
        int mark = 0;
        
        for( int i = 31; i >= 0; i -- )
        {
            temp = 1 << i;
            //printf( "temp: %u,\t i: %d\t, divisor1: %d\t divi&temp: %d\n", temp, i, divisor1, (divisor1 & temp) );
            if( (divisor1 & temp) > 0 )
            {
                mark = i;
                break;
            }
        }
        
        printf("mark: %d\n", mark);
        
        for( int i = 31 - mark; i >= 0; i -- )
        {
            
            temp = grow + (divisor1 << i);
            if( temp > dividend1 )
            {
                continue;
            }
            
            grow = temp;
            result += (1 << i);
            
            
            //printf( "%d added, now %d, i: %d\n", divisor1 << i, grow, i );
            
            if( grow == dividend1 )
            {
                break;
            }
            
        }
        
        return ni ? 0-result : result;
        
    }
};