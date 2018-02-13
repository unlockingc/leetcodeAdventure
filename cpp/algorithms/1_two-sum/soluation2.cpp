class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tempMap;
        vector<int> ret;
        ret.clear();
        for(int i = 0; i < nums.size(); i++)
        {
            int value = nums[i];
            int anti = target - value;
            if( tempMap[value] == 0)
            {
                tempMap[anti] = i + 1;
            }
            else
            {
                ret.push_back(tempMap[value] - 1), ret.push_back(i);
                return ret;
            }
        }
    }
   
};
