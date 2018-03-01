class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int start = 0;
        
        for( int i = nums.size()-1; i > 0; i -- )
        {
            if(nums[i] > nums[i - 1])
            {
                start = i;
                int j = i;
                for( j = i; j < nums.size(); j ++ )
                {
                    if( nums[i - 1] >= nums[j] )
                    {
                        swap(nums[i - 1], nums[j - 1]);
                        break;
                    }
                }
                
                if( j == nums.size())
                {
                    swap( nums[i - 1], nums[j - 1] );
                }
                
                break;
            }
        }
        
        int a = start;
        int b = nums.size() - 1;
        
        while( a < b )
        {
            swap( nums[a], nums[b] );
            a ++;
            b --;
        }
    }
};