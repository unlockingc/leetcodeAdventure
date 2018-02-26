class Solution {
public:
    
    string digits;
    vector<string> answers;
    int start[11] = {'a','a','a','d','g','j','m','p','t','w','z' + 1};
    
    
    void getOneAnswer( int where, string answer  )
    {
        int temp = digits[where] - '0';
        
        if( where != digits.length() - 1 )
        {
            for( int i = start[temp]; i < start[temp + 1]; i ++ )
            {
                getOneAnswer(where + 1, answer + (char)(i));
            }
        }
        else
        {
            for( int i = start[temp]; i < start[temp + 1]; i ++ )
            {
                answers.push_back(answer + (char)(i));
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        answers.clear();
        getOneAnswer( 0, "" );
        return answers;
    }
};