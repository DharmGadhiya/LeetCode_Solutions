class Solution {
public:
    bool dh(int l , int r , string s){
        if(l == r){
            return true;
        }
        while(l <= r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0 , r = s.size()-1;
        while(l <= r){
            if(s[l] != s[r]){
                bool b1 = dh(l,r-1,s);
                bool b2 = dh(l+1,r,s);
                return (b1||b2);
            }
            l++;
            r--;
        }
        return true;
    }
};