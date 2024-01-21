class Solution {
public:

  void dfs(int row,int col,vector<vector<int>>& image, vector<vector<int>> &ans,int incolor,int color,int delrow[],int delcol[])
  { 
      int n = image.size();
      int m = image[0].size();
      ans[row][col] = color;
      for(int i = 0;i<4;i++)
      {
          int nrow = row + delrow[i];
          int ncol = col + delcol[i];

          if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == incolor && ans[nrow][ncol] != color)
          {
              dfs(nrow,ncol,image,ans,incolor,color,delrow,delcol);
          }
      }
  }








    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         vector<vector<int>> ans = image;
         int incolor = image[sr][sc];
         ans[sr][sc] = color;
         int delrow[4] = {-1,0,1,0};
         int delcol[4] = {0,1,0,-1};
         dfs(sr,sc,image,ans,incolor,color,delrow,delcol);
         return ans;
          
    }
};