class Solution {
public:
    int ans = 0;
    
    void solve(vector < int > &v,int sum,int i,int x){
        if(i==v.size())
        {
            if(x==sum)
                ans++;
            return;
        }
        solve(v,sum,i+1,x+v[i]);
        solve(v,sum,i+1,x-v[i]);
        
    }
    int findTargetSumWays(vector<int>& v, int sum) {
        ans = 0;
        solve(v,sum,0,0);
        return ans;
    }
};