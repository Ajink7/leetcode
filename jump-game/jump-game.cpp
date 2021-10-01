class Solution {
public:
    // O(N) Time Complexity Solution
    bool canJump(vector<int>& v) {
        int mx = v[0];
        for(int i=0;i<=min(mx,(int)v.size()-1);i++)
        {
            mx = max(mx,i + v[i]);
        }
        if(mx>=v.size()-1)
            return true;
        return false;
    }
};
