class Solution {
public:
    // Checks whether the given state of the sudoku is valid or not
    bool isValid(vector<vector<char>>& board, int x, int y, char c)
    {
        for(int i = 0; i < 9; i++)
        {
            if(board[i][y] == c)
                return false;
            if(board[x][i] == c)
                return false;
            if(board[3*(x / 3) + i / 3][3*(y/3) + i % 3] == c)
                return false;
        }
        
        return true;
    }
    //generates all the possible states of the sudoku and returns the valid combination
    bool solve(vector<vector<char>>& v){
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                if(v[i][j]=='.')
                {
                    for(char k = '1';k<='9';k++)
                    {
                        
                        if(isValid(v,i,j,k))
                        {
                            v[i][j] = k;
                            if(solve(v))
                                return true;
                            else
                                v[i][j] = '.';
                        } 
                        
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& v) {
        solve(v);
        return;
    }
};
