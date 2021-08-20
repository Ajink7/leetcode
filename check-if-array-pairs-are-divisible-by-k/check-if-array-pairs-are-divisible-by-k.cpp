class Solution {
public:
    bool canArrange(vector<int>& v, int k) {
        unordered_map < long long int , long long int > m;
        for(int i=0;i<v.size();i++){
            m[(long long int)(v[i]+(long long int)1000000000*k)%k]++;
        }
        for(int i=1;i<k;i++){
            if(m[i]!=m[k-i])
                return false;
        }
        if(k%2==0){
            if(m[k/2]%2)
                return false;
        }
        return true;
    }
};