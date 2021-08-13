class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        map < string , vector < string > > m;
        set < string > s1;
        for(int i=0;i<v.size();i++){
            string s = v[i];
            sort(s.begin(),s.end());
            m[s].push_back(v[i]);
            s1.insert(s);
        }
        vector < vector < string > > ans;
        for(auto i: s1)
            ans.push_back(m[i]);
        return ans;
    }
    
};