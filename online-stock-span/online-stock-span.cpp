class StockSpanner {
public:
    
    stack < pair < int , int > > s1;
    StockSpanner() {
        stack < pair < int , int >  > s;
        s1 = s;
    }
    
    int next(int x) {
        if(s1.empty()){
            s1.push({x,1});
            return 1;
        } else {
            int ans = 1;
            while(!s1.empty() && x>=s1.top().first){
                ans += s1.top().second;
                s1.pop();
            }
            s1.push({x,ans});
            return ans;
        }
        
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */