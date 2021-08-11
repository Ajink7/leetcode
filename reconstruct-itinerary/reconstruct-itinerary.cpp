class Solution {
public:
    vector < string > ans;
    map < string , priority_queue < string , vector < string > , greater < string >  > > m;
    void dfs(string s)
    {
        while(!m[s].empty())
        {
            string s1 = m[s].top();
            m[s].pop();
            dfs(s1);
        }
        ans.push_back(s);

    }
    
    
    vector<string> findItinerary(vector<vector<string>>& v) {
        
        for(int i=0;i<v.size();i++)
        {
            priority_queue < string , vector < string > , greater < string >  > pq;
            if(m.find(v[i][0])==m.end())
                m[v[i][0]] = pq;
            m[v[i][0]].push(v[i][1]);
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};