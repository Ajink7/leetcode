class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& v) {
        int x = 0,y = v[0].size()-1;
        while(x<=y)
        {
            int mid = (x+y)/2;
            int e = -2,ind = 0;
            for(int i=0;i<v.size();i++)
            {
                if(v[i][mid]>e)
                {
                    ind = i;
                    e = v[i][mid];
                }
            }
            int f = 0;
            if(mid+1<v[0].size())
            {
                if(v[ind][mid+1]>v[ind][mid])
                    f=2;
            }
            if(mid-1>=0)
            {
                if(v[ind][mid-1]>v[ind][mid])
                    f=1;
            }
            if(!f)
            {
                return {ind, mid};
            }
            if(f==1)
                y = mid-1;
            else
                x = mid +1;
        }
        return {-1};
    }
};