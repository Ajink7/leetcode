class Solution {
public:
    
    void merge(vector < int > &v, int l, int m, int r){
        vector < int > v1,v2;
        for(int i=l;i<=m;i++)
            v1.push_back(v[i]);
        for(int i=m+1;i<=r;i++)
            v2.push_back(v[i]);
        int j = 0,k = l,i=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]<v2[j]){
                v[k]=v1[i];
                i++;
            }else {
                v[k] = v2[j];
                j++;
            }
            k++;
        }
        for(;i<v1.size();i++){
            v[k] = v1[i];
            k++;
        }
        for(;j<v2.size();j++){
            v[k] = v2[j];
            k++;
        }
    }
    
    void mergesort(vector < int > &v, int l , int r){
        int m = (l+r)/2;
        if(l>=r)
            return;
        mergesort(v,l,m);
        mergesort(v,m+1,r);
        merge(v,l,m,r);
    }
    
    vector<int> sortArray(vector<int>& v) {
        mergesort(v,0,v.size()-1);
        return v;
    }
};