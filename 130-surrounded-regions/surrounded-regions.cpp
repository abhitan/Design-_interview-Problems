class Solution {
public:

   void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& board)
   {
       vis[row][col] = 1;
       int n = board.size();
       int m = board[0].size();
       int delrow[] = {-1,0,1,0};
       int delcol[] = {0,1,0,-1};
       for(int i = 0;i<4;i++)
       {
           int nrow = row + delrow[i];
           int ncol = col + delcol[i];

           if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' and vis[nrow][ncol] == 0)
           {
               dfs(nrow,ncol,vis,board);
           }
       }
   }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        // step 1:- Figure out th boundary O'S and mark all the O'S connected to it as visited.

        for(int i = 0;i<m;i++)
        {
            if(vis[0][i] == 0 && board[0][i] == 'O')
            {
                dfs(0,i,vis,board);
            }

            if(vis[n-1][i] == 0 && board[n-1][i] == 'O')
            {
                dfs(n-1,i,vis,board);
            }       
        }

        for(int j = 0;j<n;j++)
        {
            if(vis[j][0] == 0 && board[j][0] == 'O')
            {
                dfs(j,0,vis,board);
            }

            if(vis[j][m-1] == 0 && board[j][m-1] == 'O')
            {
                dfs(j,m-1,vis,board);
            }
        }


      // step 2: mark all the remaining O's as X's.
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(board[i][j] == 'O' && vis[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};