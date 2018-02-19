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