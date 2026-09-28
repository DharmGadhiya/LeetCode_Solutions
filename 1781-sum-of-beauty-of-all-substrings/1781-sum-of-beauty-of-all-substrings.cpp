class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        for(int st = 0 ; st < n-1 ; st++){
            vector<int> vv(26,0);
            vv[s[st]-'a'] = 1;
            for(int en = st + 1 ; en < n ; en++){
                vv[s[en] - 'a']++;
                int m1 = INT_MIN;
                int m2 = INT_MAX;
                for(auto el : vv)
                {
                    m1 = max(m1,el);
                    if(el != 0){
                        m2 = min(m2,el);
                    }
                }
                ans+=(m1-m2);
            }
        }
        return ans;
    }
};