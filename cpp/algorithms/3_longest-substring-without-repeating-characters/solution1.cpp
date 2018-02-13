struct myIndex {
    int start;
    int end;

    myIndex():start(0),end(0){

    }

    myIndex& operator =(const myIndex& c)
    {
        this->start = c.start;
        this->end   = c.end;
        return *this;
    }

    const int length()
    {
        return this->end - this->start + 1;
    }

    bool operator < (myIndex& c)
    {
        return length() < c.length();
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        myIndex longest;
        myIndex border;
        myIndex borderCut;

        bool isBorder = true;
        int alphabet[256];
        memset(alphabet,0,sizeof(int)*256);

        char current;

        alphabet[s[0]] = 1;

        for( int i = 1; i < s.length(); i++ )
        {
            current = s[i];
            if(alphabet[current] == 0)
            {
                border.end = i;
                alphabet[current] = i+1;
                borderCut.start = -1;
                borderCut.end = -2;
            }
            else
            {
                for(int j = border.start; j < alphabet[current] - 1; j++)
                {
                    alphabet[s[j]] = 0;
                }

                borderCut.start = border.start;
                borderCut.end = alphabet[current] - 1;

                border.end = i;
                border.start = alphabet[current];

                alphabet[current] = i+1;
            }


            isBorder =  longest < border ? ( border < borderCut ? false : true ) : false;
            longest  =  longest < border ? ( border < borderCut ? borderCut : border ) : longest;

        }

        return s.length() == 0 ? 0 : longest.length();
    }


};
