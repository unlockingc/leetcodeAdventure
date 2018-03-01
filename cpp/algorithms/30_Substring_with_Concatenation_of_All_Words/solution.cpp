class Solution {
public:
    bool judge(string s, vector<string>& words) {
        int w = words[0].length();
        int nums = words.size();
        // cout << w << " " << nums << endl;
        vector<int> check(nums, 0);
        string temp;

        int sum = 0, j;
        for(int i = 0; i < nums; i++) {
            temp = s.substr(i*w, w);
            // cout << temp << endl;
            for(j = 0; j < nums; j++) {
                // cout << words[j] << " " << check[j] << endl;
                if (!check[j]) {
                    if (temp == words[j]) {
                        check[j] = 1;
                        sum += 1;
                        break;
                    }
                }
            }
            if (j == nums)
                return false;
        }
        if (sum == nums)
            return true;
        else
            return false;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        int w = words[0].length();
        int len = s.length();
        int nums = words.size();
        int ite = len - w * nums;

        // cout << w << " " << len << " " << nums << " " << ite << endl;
        for(int i = 0; i <= ite; i++) {
            // cout << s.substr(i, nums*w) << endl;
            if (judge(s.substr(i, nums*w), words)) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
