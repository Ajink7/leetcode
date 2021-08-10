class Solution {
public:
    int jump(vector<int>& v) {
        vector < int > ans(v.size(),INT_MAX);
        ans[0] = 0;
        int mx = v[0];
        for(int i=0;i<v.size();i++)
        {
            for(int j=1;j<=v[i] && j+i<v.size();j++)
            {
                ans[i+j] = min(ans[i+j],ans[i]+1);
            }
        }
        return ans[v.size()-1];
    }
};