class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        bool dd = true;
        int n = s.size();
        for (int i = 0; i < n - 1; i++) {
            if (mp[s[i]] >= mp[s[i + 1]]) {

                ans += mp[s[i]];
            } else {
                if (i == n - 2) {
                    dd = false;
                }
                ans += (mp[s[i + 1]] - mp[s[i]]);
                i++;
            }
        }
        if (dd) {
            ans += mp[s[n - 1]];
        }
        return ans;
    }
};