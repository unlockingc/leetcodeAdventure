class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();
        
        int temp = 0;
        while( start < end)
        {
            temp = start + (end - start)/2;
            
            if( nums[temp] == target )
            {
                return temp;
            }
            else if( nums[temp] < target )
            {
                start = temp + 1;
            }
            else
            {
                end = temp;
            }
            
            //cout << "start: " << start << "  end: " << end << endl;
        }
        
        return end;
    }
};