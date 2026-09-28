class Solution {
public:
    double ch(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double c = ch(x, (n / 2));
        if (n & 1) {
            return (x * c * c);
        } else {
            return (c * c);
        }
    }

    double myPow(double x, int n) {
        double ans = ch(x,n);
        if(n < 0){
            ans = 1/ans;
        }
        return ans;
    }
};