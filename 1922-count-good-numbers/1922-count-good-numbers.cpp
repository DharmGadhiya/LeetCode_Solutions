class Solution {
public:
    int mod = 1e9 + 7;
    int dh(int a, long long b) {
        if (b == 1) {
            return a;
        }
        if(b==0){
            return 1;
        }
        int x = dh(a, b / 2);
        int ans = (x * 1ll * x) % mod;
        if (b & 1) {
            ans = (ans * 1ll * a) % mod;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        int c = dh(5, n / 2);
        int d = dh(4, n / 2);
        int ans = (c *1ll*d) % mod;
        if (n & 1) {
            ans = (ans * 5ll) % mod;
        }
        return ans;
    }
};