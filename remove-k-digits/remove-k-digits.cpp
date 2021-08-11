class Solution {
public:
    string removeKdigits(string s, int k) {
        stack < int > st;
        string ans;
        int x = 0;
        if(k==s.size())
            return "0";
        for(int i=0;i<s.size();i++)
        {
            if(x==k)
            {
                st.push(s[i]-'0');
            }
            else if(st.empty())
                st.push(s[i]-'0');
            else
            {
                if(s[i]-'0'<st.top())
                {
                     while(!st.empty() && s[i]-'0'<st.top()  && x<k)
                    {
                        st.pop();
                        x++;
                        
                    }
                    st.push(s[i]-'0');
                }
                else
                    st.push(s[i]-'0');
            }
        }
        while(x<k && !st.empty())
        {
            st.pop();
            x++;
        }
        while(!st.empty())
        {
            ans += (st.top()+'0');
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i = 0;
        while(i<ans.size() && ans[i]=='0')
            i++;
        if(ans.substr(i)=="")
            return "0";
        return ans.substr(i);
    }
};