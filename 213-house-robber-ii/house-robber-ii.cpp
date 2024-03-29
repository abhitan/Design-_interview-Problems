class Solution {
public:

   int houseRobber(vector<int>&nums)
   {
       int n = nums.size();
       vector<int>dp(n+1,0);
       dp[0] = nums[0];

       for(int i = 1;i<n;i++)
       {
           int take = nums[i];
           if(i>1)
           {
               take += dp[i-2];
           }
           int notTake = dp[i-1];
           dp[i] = max(take,notTake);
       }
       return dp[n-1];
   }





    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>temp1,temp2;

        for(int i = 0;i<n;i++)
        {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        int op1 = houseRobber(temp1);
        int op2 = houseRobber(temp2);

        return max(op1,op2);
    }
};