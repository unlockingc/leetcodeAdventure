class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if( nums.size() == 0 )
        {
            return 0;
        }

        int ret = 1;

        for( vector<int>::iterator it = nums.begin(); it < nums.end() - 1; it ++ )
        {
            if( *it == *(it + 1) )
            {
                nums.erase(it);
                it --;
            }
            else
            {
                ret ++;
            }
        }



        return ret;
    }
};
