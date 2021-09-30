#define lli long long int
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        lli x = numerator, y = denominator;
        string ans;
        if((x<0 && y>0) || (x>0 && y<0))
            ans += '-';
        lli z = abs(x)/abs(y);
        ans += to_string(z);
        z = abs(x%y);
        x = abs(x);
        y = abs(y);
        unordered_map < lli ,lli > m;
        string s1;
        while(z){
            if(m[z]){
                s1.insert(m[z]-1,"(");
                return ans + "." + s1 + ")";
            } else {
                m[z] = s1.size()+1;
                z = (lli)(10*z);
                s1 += to_string(z/y);
                z = z%y;
            }
        }
        if(s1.size())
        return ans + "." + s1;
        return ans;
    }
};