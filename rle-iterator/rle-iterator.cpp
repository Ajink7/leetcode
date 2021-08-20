class RLEIterator {
public:
    vector < int > v;
    int i=0;
    RLEIterator(vector<int>& encoding) {
        v = encoding;
        i = 0;
    }
    
    int next(int n) {
        while(n>0){
            if(i>=v.size())
                return -1;
            if(v[i]<n){
                n -= v[i];
                v[i] = 0;
                i = i+2;
            } else if(v[i]==n){
                n = 0;
                v[i] = 0;
                return v[i+1];
            } else {
                v[i] -= n;
                n = 0;
                return v[i+1];
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */