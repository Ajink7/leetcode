class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        stack < int > st;
        v.insert(v.begin(),0);
        v.push_back(0);
        int ans = 0;
        for(int i=0;i<v.size();i++){
            
            while(!st.empty() && v[st.top()]>v[i]){
                int x = st.top();
                st.pop();
                int height = v[x],length  = i - st.top() -1;
                ans = max(height*length,ans);
                //st.pop();
            }
            st.push(i);
            
        }
        
        return ans;
    }
};