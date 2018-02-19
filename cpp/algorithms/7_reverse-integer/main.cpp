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

using namespace std;


class Solution {
public:
    int reverse(int x) {
        string temp = to_string(x);
        printf("number: %d string: %s\n",x, temp.c_str());
        int base = 0;
        if(temp[0] == '-')
        {
            base = 1;
        }
        for(int i = 0; i < temp.length()/2; i ++)
        {
            swap(temp[i + base],temp[temp.length()-1-i]);
        }
        printf("reverse string: %s\n", temp.c_str());


        int ret = 0;

        try //try里面是可能引发异常代码块
        {
            ret = stoi(temp);
        }
        catch(std::out_of_range &exc)
        {
            ret = 0;
        }

        return ret;

    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}