class Solution {
public:
    bool solve(string &s,string &p,int i,int j,int pass,vector<vector<int>> &dp){
        if(i==s.size() && j>=p.size())
            return true;
        else if(i==s.size()){
            if(p[j]!='*')
                return 0;
            return solve(s,p,i,j+1,1,dp);
        }
        else if(dp[i][j]!=-1)
            return dp[i][j];
        // else if(pass)
        // {
        //     if(s[i]==p[j] || p[j]=='?')
        //     return dp[i][j] = solve(s,p,i+1,j+1,0,dp) || solve(s,p,i+1,j,1,dp) || solve(s,p,i,j+1,0,dp);
        //     return dp[i][j] = solve(s,p,i+1,j,1,dp) || solve(s,p,i,j+1,0,dp);
        // }
        else if(s[i]==p[j] || p[j]=='?')
            return dp[i][j] = solve(s,p,i+1,j+1,0,dp);
        else if(p[j]=='*')
            return dp[i][j] = solve(s,p,i+1,j+1,1,dp) || solve(s,p,i+1,j,0,dp) || solve(s,p,i,j+1,0,dp);
        else
            return  dp[i][j] = 0;
        
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+5,vector<int> (p.size()+5,-1));
        if(p.size() && p[0]=='*')
            return solve(s,p,0,0,1,dp);
        return solve(s,p,0,0,0,dp);
    }
};