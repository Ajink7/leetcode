class Solution {
public:
    int minPatches(vector<int>& v, int n) {
        long long int mx = 0,count = 0,i=0;
        while(mx<n){
            if(i<v.size() && v[i]<=mx+1){
                mx += v[i];
                i++;
            } else {
                mx += mx + 1;
                count++;
            }
        }
        return count;
    }
};