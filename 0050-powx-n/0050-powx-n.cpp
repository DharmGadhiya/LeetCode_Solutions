class Solution {
public:
   
    double myPow(double x, int n) {
        int a = 0;
        if(n == 0){
            return 1;
        }
        else if(n == 1){
            return x;
        }
        else if(n == INT_MIN){
            a = INT_MAX;
        }
        else{
            a = abs(n);
        }
        
        double y = myPow(x,a/2);
        double ans = y*y;
        if(a & 1){
            ans *= x;
        }
        if(n == INT_MIN){
            ans*=x;
        }
        if(n < 0)
        {
            ans = 1/ans;
        }
        return ans;
        
    }
};