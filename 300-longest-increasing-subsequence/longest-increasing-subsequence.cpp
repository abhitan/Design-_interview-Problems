class Solution {
public:

   int solve(vector<int>& nums,int n,int ind,int prev_ind, vector<vector<int>>&dp)
   {
       if(ind == n)
       {
           return 0;
       }

       if(dp[ind][prev_ind+1] != -1)
       {
           return dp[ind][prev_ind+1];
       }

       int len = solve(nums,n,ind+1,prev_ind,dp); // Not Take case
       if(prev_ind == -1 || nums[ind] > nums[prev_ind])
       len = max(len,1 + solve(nums,n,ind+1,ind,dp)); // Take Case

       return dp[ind][prev_ind+1] = len;
   }





    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(nums,n,0,-1,dp);
    }
};