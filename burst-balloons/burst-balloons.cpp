class Solution {
public:
    
    vector < vector < int > > dp;
    vector < int > v1;
    int solve(int x,int y){
        if(x>y)
            return 0;
        if(dp[x][y]!=-1)
            return dp[x][y];
        if(x==y)
        {
            int p = v1[x];
            if(x>0)
                p *= v1[x-1];
            if(x<v1.size()-1)
                p*= v1[x+1];
            return dp[x][y] = p;
        }
        int ans = 0;
        int p = 1;
        if(x>0)
            p *= v1[x-1];
        if(y<v1.size()-1)
            p*= v1[y+1];
        for(int i=x;i<=y;i++){
            ans = max(ans,solve(x,i-1) + solve(i+1,y) + p*v1[i]);
        }
        return dp[x][y] = ans;
    }
    int maxCoins(vector<int>& v) {
        v1 = v;
        dp.resize(v.size()+1,vector < int > (v.size()+1,-1));
        return solve(0,v.size()-1);
    }
};