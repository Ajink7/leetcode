class Solution {
public:
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &dp)
{
	if(k == 0 and (i or j))
		return false;

	if(i == 0 and j == 0 and k == 0)
		return true;

	if(dp[i][j] != -1) // Just return the result from the cache
		return dp[i][j];

	if(i > 0 and j > 0 and s1[i-1] == s2[j-1] and s1[i-1] == s3[k-1])
		return dp[i][j] = solve(s1, s2, s3, i-1, j, k-1, dp) || solve(s1, s2,s3, i, j-1, k-1, dp); // before returning the result store it into the cache

	if(i > 0 and s3[k-1] == s1[i-1])
		return dp[i][j] = solve(s1, s2, s3, i-1, j, k-1, dp);

	if(j > 0 and s3[k-1] == s2[j-1])
		return dp[i][j] = solve(s1, s2,s3, i, j-1, k-1, dp);

	return dp[i][j] = false;
}

bool isInterleave(string s1, string s2, string s3) {

	vector<vector<int>> dp(s1.size() + 1, vector<int> (s2.size() + 1, -1)); // initialisiation of 2D vector

	if(s1.size() + s2.size() != s3.size())
		return false;

	return solve(s1, s2, s3, s1.size(), s2.size(), s3.size(), dp);
}
};