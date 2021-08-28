class Solution {
public:
    int jobScheduling(vector<int>& v1, vector<int>& v2, vector<int>& p) {
        vector < vector < int > > v;
        for(int i=0;i<v1.size();i++)
        {
            v.push_back({v1[i],v2[i],p[i]});
        }
        sort(v.begin(),v.end());
        int ans = v[v.size()-1][2];
        vector < int > dp(v.size(),0);
        dp[v.size()-1] = ans;
        for(int i=v.size()-2;i>=0;i--)
        {
            if(v[i][1]>v[v.size()-1][0])
                dp[i] = max(dp[i+1],v[i][2]);
            else
            {
                int low = i+1,high = v.size()-1;
                int mid = (low + high)/2,pos;
                while(low<=high)
                {
                    mid = (low + high)/2;
                    if(v[mid][0]>=v[i][1])
                    {
                        high = mid - 1;
                        pos= mid;
                    }
                    else if(v[mid][0]<v[i][1])
                        low = mid + 1;
                    
                }
                dp[i] = max(dp[i+1],v[i][2]+dp[pos]);
            }
        }
        return dp[0];
    }
};