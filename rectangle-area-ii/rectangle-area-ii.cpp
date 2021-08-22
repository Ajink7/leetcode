class Solution {
public:
    void overlap(queue<vector<int>>&q, vector<int>a)
    {
        if(q.empty())
            q.push(a);
        else
        {
            int s = q.size();
            while(s--)
            {
                vector<int> t = q.front();
                q.pop();
                
                // get non-overlapping rectangles from current rectangle and previous rectangle intersection
                if(a[0]<=t[2] && a[2]>=t[0] && a[1]<=t[3] && a[3]>=t[1])
                {                    
                    if(a[0] > t[0])q.push({t[0],t[1],a[0],t[3]});
                    if(a[3] < t[3])q.push({max(a[0],t[0]),a[3],t[2],t[3]});
                    if(a[1] > t[1])q.push({max(a[0],t[0]),t[1],t[2],a[1]});
                    if(a[2] < t[2])q.push({a[2],max(a[1],t[1]),t[2],min(t[3],a[3])});
                }
                else q.push(t);
            }
            q.push(a);
        }
    }

    int rectangleArea(vector<vector<int>>& v) {
        queue < vector < int > > q;
        for(int i=0;i<v.size();i++)
        {
            overlap(q,v[i]);
        }
        
        long long int ans = 0;
        while(!q.empty())
        {
            vector < int > x = q.front();
            q.pop();
            ans = (ans + (long long int)(x[2]-x[0])*(x[3] - x[1]))%1000000007;
        }
        return ans;
    }
};