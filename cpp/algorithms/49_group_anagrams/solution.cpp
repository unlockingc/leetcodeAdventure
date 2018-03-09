class Solution {
public:
    double pNums[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

       // vector<double> temp;
        unordered_map<double,vector<string>> toRet;
        double a = 1;
        for( int i = 0; i < strs.size(); i ++ )
        {
            a = 1;
            for( int j = 0; j < strs[i].length(); j++ )
            {
                a = a*pNums[(int)(strs[i][j]  - 'a')];
            }
            toRet[a].push_back(strs[i]);
        }

        vector<vector<string>> ret;

        for( unordered_map<double,vector<string>>::iterator iter=toRet.begin(); iter!=toRet.end(); iter++ )
        {
            ret.push_back(iter->second);
        }

        return ret;
    }
};
