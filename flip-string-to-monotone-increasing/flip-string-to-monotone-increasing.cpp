class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int x = 0, y = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
                y++;
            else
                x++;
            x = min(x,y);
        }
        return x;
    }
};