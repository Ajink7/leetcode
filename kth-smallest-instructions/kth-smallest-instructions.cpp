class Solution {
public:
    vector < vector < int > > dp;
    int n,m;
    int solve(int x,int y){
        if(x>n || y>m)
            return 0;
        if(x==n || y==m)
            return dp[x][y] = 1;
        if(dp[x][y]!=0)
            return dp[x][y];
        return dp[x][y] = solve(x+1,y) + solve(x,y+1);
    }
    
    string kthSmallestPath(vector<int>& v, int k) {
        n = v[0];
        m = v[1];
        dp.resize(n+1,vector < int > (m+1,0));
        solve(0,0);
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=m;j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<"\n";
        // }
        int i= 0,j = 0;
        string ans = "";
        while(i<=n && j<=m){
            while(j<=m && solve(i,j)>=k){
                j++;
                ans += 'H';
            }
            if(ans.size()!=0)
            ans.pop_back();
            j--;
            if(j>m)
                break;
            k -= solve(i,j+1);
            
            i++;
            if(i>n)
                break;
            ans += 'V';
        }
        while(j<=m){
            ans += 'H';
            j++;
        }
        while(i<=n){
            ans += 'V';
            i++;
        }
        ans.pop_back();
        return ans;
    }
};