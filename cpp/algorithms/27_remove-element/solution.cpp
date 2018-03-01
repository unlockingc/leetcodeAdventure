class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // for( vector<int>::iterator it = nums.begin(); it < nums.end(); it ++ )
        // {
        //     if(*it == val)
        //     {
        //         nums.erase(it);
        //         it --;
        //     }
        // }
        
        int size = nums.size();
        
        for( int i = 0; i < size; i ++ )
        {
            if(nums[i] == val)
            {
                nums[i] = nums[size - 1];
                size --;
                i --;
            }
        }
        
        return size;
    }
};