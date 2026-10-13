class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
       vector<int> dp(n ,0);
        int c = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > c) {
                dp[i] = max(prices[i] - c, dp[i-1]);
            }
            else{
                c = prices[i];
                dp[i] = dp[i-1];
            }
        }

        return dp[n-1];
    }
};