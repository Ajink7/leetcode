class Solution {
public:
    bool canJump(vector<int>& v) {
        //vector < int > ans(v.size(),0);
        //ans[0] = 1;
        int mx = v[0];
        for(int i=0;i<=min(mx,(int)v.size()-1);i++)
        {
            mx = max(mx,i + v[i]);
            //cout<<mx<<" ";
        }
        if(mx>=v.size()-1)
            return true;
        return false;
    }
};