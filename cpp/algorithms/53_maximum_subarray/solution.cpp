// struct myInterval
// {
// public:
//     int start;
//     int end;
//     myInterval(): start(0), end(0)
//     {}

//     myInterval( int start_, int end_ ): start(start_), end(end_)
//     {}

//     void set( int start_, int end_ )
//     {
//         start = start_;
//         end = end_;
//     }

//     myInterval& operator = ( const myInterval& c )
//     {
//         this->start = c.start;
//         this->end = c.end;
//         return *this;
//     }

// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if( nums.size() == 0 )
        {
            return 0;
        }

        int max = nums[0];
        int border = nums[0];

        for( int  i = 1; i < nums.size(); i++ )
        {
            border += nums[i];
            //borderI.end = nums[i];

            if( border < nums[i] )
            {
                border = nums[i];
              //  borderI.start = i;
            }

            //maxI = max > border ? maxI : borderI;
            max = max > border ?  max : border;

        }

        return max;
    }
};
