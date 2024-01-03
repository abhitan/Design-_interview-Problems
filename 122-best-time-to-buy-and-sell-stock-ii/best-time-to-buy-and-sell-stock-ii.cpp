class Solution {
public:

   int solve(vector<int>& prices,int n,int ind,int buy, vector<vector<int>>&dp)
   {
       int profit = INT_MIN;

       if(ind == n)
       {
           return 0;
       }

       if(dp[ind][buy] != -1)
       {
           return dp[ind][buy];
       }

       if(buy)
       {
           int op1 = -prices[ind] + solve(prices,n,ind+1,0,dp);
           int op2 = 0 + solve(prices,n,ind+1,1,dp);

           profit = max(op1,op2);
       }
       else
       {
           int op1 = prices[ind] + solve(prices,n,ind+1,1,dp);
           int op2 = 0 + solve(prices,n,ind+1,0,dp);
           profit = max(op1,op2);
       }
      return dp[ind][buy] = profit;
   }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(prices,n,0,1,dp);
    }
};