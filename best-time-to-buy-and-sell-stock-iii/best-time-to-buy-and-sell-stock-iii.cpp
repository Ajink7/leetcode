class Solution {
public:
    int sol(int i,int B,int choice,vector<int> &A,vector<vector<vector<int>>> &dp){
    if(i>=A.size() || B<=0)
    return 0;
    if(dp[i][B][choice]!=-1)
    return dp[i][B][choice];
    if(choice){
        int ans = -A[i];
        ans += sol(i+1,B,1-choice,A,dp);
        ans = max(ans,sol(i+1,B,choice,A,dp));
        return dp[i][B][choice] = ans;
    } else {
        int ans = A[i];
        ans += sol(i+1,B-1,1-choice,A,dp);
        ans = max(ans, sol(i+1,B,choice,A,dp));
        return dp[i][B][choice] = ans;
    }
}

int solve(vector<int> &A, int B) {
    B = min(B,(int)A.size());
    vector<vector<vector<int>>> dp(A.size()+1,vector<vector<int>>(B+1,vector<int>(2,-1)));
    return sol(0,B,1,A,dp);
}

    int maxProfit(vector<int>& prices) {
        return solve(prices,2);
    }
};