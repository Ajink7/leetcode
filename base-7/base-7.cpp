class Solution {
public:
     string convertToBasen(int num,int n) {
        if(num==0)
            return "0";
        int x = abs(num);
        string ans;
        while(x){
            ans += (char)(x%n + '0');
            x = x/n;
        }
        if(num<0)
            ans += '-';
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string convertToBase7(int num) {
        if(num==0)
            return "0";
        int x = abs(num);
        string ans;
        while(x){
            ans += (char)(x%7 + '0');
            x = x/7;
        }
        if(num<0)
            ans += '-';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
