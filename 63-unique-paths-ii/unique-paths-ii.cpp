class Solution {
public:
 int helper(vector<vector<int>>& mat,int i,int j, vector<vector<int>>&dp)
 {
     if(i >= 0 and j >= 0 and mat[i][j] == 1)
     {
         return  0;
     }
     if(i == 0 and j == 0)
     {
         return  1;
     }
     if(i < 0 or j < 0)
     {
         return 0;
     }
     if(dp[i][j] != -1)
     {
         return dp[i][j];
     }

     int up = helper(mat,i-1,j,dp);
     int left = helper(mat,i,j-1,dp);

     return dp[i][j] = up + left;
 }






    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        int i = m-1;
        int j = n-1;

        return helper(obstacleGrid,i,j,dp);
       
    }
};