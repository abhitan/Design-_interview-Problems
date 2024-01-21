class Solution {
public:
int dp[1001][1001];


 int helper(vector<vector<int>>& mat,int i,int j)
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

     int up = helper(mat,i-1,j);
     int down = helper(mat,i,j-1);

     return dp[i][j] = up + down;
 }






    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        memset(dp,-1,sizeof(dp));

        int i = m-1;
        int j = n-1;

        return helper(obstacleGrid,i,j);
       
    }
};