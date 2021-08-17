class Solution {
public:
    int arrayNesting(vector<int>& v) {
        vector < vector < int > > adj;
        adj.resize(v.size());
        int sum = 0;
        for(int i=0;i<v.size();i++){
            int ans = 0,j = i;
            if(v[i]==-1){
                continue;
            } else {
                while(v[j]!=-1){
                    int x = v[j];
                    v[j] = -1;
                    j = x;
                    ans++;
                }
                sum = max(sum,ans);
            }
            
        }
        return sum;
    }
};