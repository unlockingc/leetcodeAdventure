class Solution {
public:
    int jump(vector<int>& nums) {
        
        
        cout << nums.size() - 1 << endl;
        if( nums.size() <= 1 )
        {
            return 0;
        }
        else if( nums[0] >= (nums.size() - 1) )
        {
            return 1;
        }
        
        int size = nums.size();
        
        int nowIndex = 0;
        int pre = 0;
        
        int maxIndex = 0;
        int mymax = 0;
        int now = 0;
        
        
        int temp = 0;
        
        while( true )
        {
            
            //cout << "nowIndex: " << nowIndex <<" pre: "  << pre <<endl;
            mymax = -1;
            
            for( int i = (pre > (nowIndex + 1))? pre : (nowIndex + 1); i <= (nowIndex + nums[nowIndex]); i ++ )
            {
                temp = i +  nums[i];
                if( temp >= (size -1) )
                {
                    return now + 2;
                }
                else if( mymax < temp )
                {
                    mymax  = temp;
                    maxIndex = i;
                }
            }
            
            now ++;
            pre = nowIndex + nums[nowIndex];
            nowIndex = maxIndex;
        }
        
        return 0;
    }
    
};