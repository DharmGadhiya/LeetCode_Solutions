class Solution {
public:
    string dh(int l, int r , int n , string s) {
        string t;
     
        while (l >= 0 && r < n) {
            if (s[l] == s[r]) {
                l--;
                r++;
            } else {
                break;
            }
        }
        l++;
        r--;
        t = s.substr(l,r-l+1);
        return t;
    }
    string longestPalindrome(string s) {
        string ans;
        ans+=s[0];
        int n = s.size();
        if (n == 1) {
            return ans;
        } else if (n == 2) {
            return s[0] == s[1] ? s : ans;
        }
        string t;
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            t = dh(i,i,n,s);      
            if(t.size() > ans.size()){
                ans = t;
            }
            t = dh(i-1 , i ,n ,s);
                 if(t.size() > ans.size()){
                ans = t;
            }
        }
        return ans;
    }
};