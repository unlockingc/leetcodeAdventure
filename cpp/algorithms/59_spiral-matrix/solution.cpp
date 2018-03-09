class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ret;
        
        for( int i = 0; i < n; i ++ )
        {
            vector<int> temp( n,0 );
            ret.push_back(temp);
        }
        
        int direction = 0;
        int jLeft = 0;
        int jRight = n - 1;
        int iUp = 0;
        int iDown = n - 1;
        int count = 0;
        
        
        int i = 0;
        int j = 0;
        
        while( count < n*n )
        {
            
            //printf( "i: %d\tj:%d\tcount:%d\n",i,j,count );
            ret[i][j] = count + 1;
            switch(direction)
            {
                case 0:
                    {
                        if( j == jRight )
                        {
                            iUp ++;
                            direction = 1;
                            count --;
                        }
                        else
                        {
                            j ++;
                        }
                        break;
                    }
                case 1:
                    {
                        if( i == iDown )
                        {
                            jRight --;    
                            direction = 2;
                            count --;
                        }
                        else
                        {
                            i ++;
                        }
                        break;
                    }
                case 2:
                    {
                        if( j == jLeft )
                        {
                            iDown --;
                            direction = 3;
                            count --;
                        }
                        else
                        {
                            j --;
                        }
                        break;
                    }
                case 3:
                    {
                        if( i == iUp )
                        {
                            jLeft ++;
                            direction = 0;
                            count --;
                        }
                        else
                        {
                            i --;
                        }
                        break;
                    }
                default:
                    {
                        cout << " wrong: "  << direction << endl;
                        break;
                    }
            }
            
            count ++;
        }
        
        return ret;
        
    }
};