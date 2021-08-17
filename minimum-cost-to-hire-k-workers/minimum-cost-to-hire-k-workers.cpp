class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        vector < pair < double , int > > v;
        for(int i=0;i<q.size();i++){
            v.push_back({(double)w[i]/q[i],q[i]});
        }
        sort(v.begin(),v.end());
        priority_queue < int > pq;
        int qual = 0;
        for(int i=0;i<k;i++){
            pq.push(v[i].second);
            qual += v[i].second;
        }
        double ans = qual*v[k-1].first;
        for(int i=k;i<v.size();i++){
            qual -= pq.top();
            pq.pop();
            qual += v[i].second;
            pq.push(v[i].second);
            ans = min(ans,qual*v[i].first);
        }
        return ans;
    }
};