class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;
        
        int sum=0;
        int x_old=x;
        int count = 1;
        
        
        //count保证sum头没有空0
        //x_old保证奇位数能被正确检测
        while( sum <= x_old )
        {
            
            if( (sum == x || sum == x_old) && sum >= count/10 )
                return true;
            
            sum=sum*10+x%10;
            
            x_old = x;
            x /=10;
            count *=10;
        }
        
        
        return false;
    }
};