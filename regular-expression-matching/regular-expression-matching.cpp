class Solution {
public:
    
     bool solve(string &s,string &p,int i,int j,vector<vector<int>> &dp){
        if(i>=s.size() && j>=p.size())
            return true;
        if(i>=s.size()){
            if(j==p.size()-1 && p[j]!='*')
                return false;
            if(p[j]!='*' && p[j+1]!='*')
                return false;
            return solve(s,p,i,j+1,dp);
        } 
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(p[j]=='*'){
            if(p[j-1]==s[i] || p[j-1]=='.')
                return dp[i][j] = solve(s,p,i+1,j,dp) || solve(s,p,i,j+1,dp) || solve(s,p,i+1,j+1,dp);
            return dp[i][j] = solve(s,p,i,j+1,dp);
        }
        if(p[j]=='.' || p[j]==s[i]){
            if(j+1<p.size() && p[j+1]=='*')
                 return dp[i][j] = solve(s,p,i+1,j+1,dp) || solve(s,p,i,j+1,dp);
            
            return dp[i][j] = solve(s,p,i+1,j+1,dp);
        }
        if(j+1<p.size() && p[j+1]=='*')
            return dp[i][j] = solve(s,p,i,j+2,dp);
        return false; 
         
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+5,vector<int> (p.size()+5,-1));
        return solve(s,p,0,0,dp);
    }
   
};