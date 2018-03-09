class Solution {
public:
    bool canJump(vector<int>& nums) {
        cout << nums.size() - 1 << endl;
        if( nums.size() <= 1 )
        {
            return true;
        }
        else if( nums[0] >= (nums.size() - 1) )
        {
            return true;
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
                    return true;
                }
                else if( mymax < temp )
                {
                    mymax  = temp;
                    maxIndex = i;
                }
            }

            if( nowIndex == maxIndex )
            {
                return false;
            }

            now ++;
            pre = nowIndex + nums[nowIndex];
            nowIndex = maxIndex;
        }

        return false;
    }
};
