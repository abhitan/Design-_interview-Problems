class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }
        
        int maxTime = 0;
        
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            maxTime = max(maxTime,t);
        

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        for(int i = 0;i<4;i++)
        {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            
            
            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] == 1 and vis[nrow][ncol] == 0)
            {
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol] = 2;
            }
        }
        }
        
        for(int i = 0;i<n;i++)
        {
            for(int j =0 ;j<m;j++)
            {
                if(grid[i][j] == 1 and vis[i][j] == 0)
                {
                    return -1;
                }
            }
        }
        return maxTime;
        
    }
};