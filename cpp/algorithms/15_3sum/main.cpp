#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <exception>
#include <map>
#include <list>
#include <algorithm>
#include <time.h>
#include <memory.h>
#include <assert.h>
#include <unordered_map>

using namespace std;


struct fuck
{
    int a;
    int b;

    fuck( int& i, int& j ):a(i),b(j)
    {}


    fuck():a(0),b(0)
    {}

    void set(int& i, int& j)
    {
        a = i;
        b = j;
    }

    fuck& operator=( const fuck* c)
    {
        this->a = c->a;
        this->b = c->b;
        return *this;
    }
};

class Solution {
public:

    unordered_map<int, unordered_map<int,fuck>> tempMap;
    unordered_map<int, int> hasMap;


    vector<vector<int>> threeSum(vector<int>& nums) {

        for( int i = 0; i < nums.size(); i++ )
        {
            for( int j = i + 1; j < nums.size(); j ++ )
            {
                if( tempMap[0 - nums[i] - nums[j]].find(nums[j]) == tempMap[0 - nums[i] - nums[j]].end() )
                {
                    tempMap[0 - nums[i] - nums[j]][nums[i]].set(i,j);
                }
                //tempMap[0 - nums[i] - nums[j]][nums[j]] = 1;
            }
        }

        vector<vector<int>> ret;

        for( int i = 0; i < nums.size(); i ++ )
        {
            if( hasMap[nums[i]] == 0 )
            {
                hasMap[nums[i]] = 1;
            }
            else
            {
                continue;
            }

            if( tempMap.find(nums[i]) != tempMap.end() )
            {
                for( unordered_map<int,fuck>::iterator iter=tempMap[nums[i]].begin(); iter!=tempMap[nums[i]].end(); iter++ )
                {
                    if( i != iter->second.a && i != iter->second.b )
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(iter->first);
                        temp.push_back(0 - nums[i] - iter->first);
                        ret.push_back(temp);

                        if( nums[i] != nums[iter->second.a] && tempMap[nums[iter->second.a]].find(nums[i]) != tempMap[nums[iter->second.a]].end() )
                        {
                            tempMap[nums[iter->second.a]].erase(nums[i]);
                        }
                        if( nums[i] != nums[iter->second.a] && tempMap[nums[iter->second.a]].find(nums[iter->second.b]) != tempMap[nums[iter->second.a]].end() )
                        {
                            tempMap[nums[iter->second.a]].erase(nums[iter->second.b]);
                        }
                        if( nums[i] != nums[iter->second.b] && tempMap[nums[iter->second.b]].find(nums[i]) != tempMap[nums[iter->second.b]].end() )
                        {
                            tempMap[nums[iter->second.b]].erase(nums[i]);
                        }
                        if( nums[i] != nums[iter->second.b] && tempMap[nums[iter->second.b]].find(nums[iter->second.a]) != tempMap[nums[iter->second.b]].end() )
                        {
                            tempMap[nums[iter->second.b]].erase(nums[iter->second.a]);
                        }

                    }
                }
            }
        }

        return ret;
    }
};



int main() {

    vector<int> input({0,0,0});
    Solution temp;
    vector<vector<int>>result = temp.threeSum(input);

    cout << "[ ";
    for(int i = 0; i < result.size(); i++ )
    {
        cout << "[";
        for( int j = 0; j < result[i].size()-1;j ++ )
        {
            cout << result[i][j] << ", ";
        }
        cout << result[i][result[i].size()-1] << "], ";
    }

    cout << "]" << endl;

    return 0;
}