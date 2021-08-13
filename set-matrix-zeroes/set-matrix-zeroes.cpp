class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        int x=0,y =0,n = v.size(),m =v[0].size();
        for(int i=0;i<n;i++)
        {
            if(v[i][0]==0)
                x = 1;
        }
        for(int i=0;i<m;i++)
        {
            if(v[0][i]==0)
                y = 1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==0)
                {
                    v[i][0] = 0;
                    v[0][j] = 0;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            if(v[i][0]==0)
            {
                for(int j=0;j<m;j++)
                    v[i][j] = 0;
            }
        }
        for(int i=1;i<m;i++)
        {
            if(v[0][i]==0)
            {
                for(int j=0;j<n;j++)
                    v[j][i] = 0;
            }
        }
        if(x){
            for(int i=0;i<n;i++)
            {
                v[i][0] = 0;
            }
        }
        if(y){
            for(int i=0;i<m;i++)
            {
                v[0][i] = 0;
            }
        }
        //return v;
    }
};