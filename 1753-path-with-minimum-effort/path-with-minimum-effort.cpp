class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0] = 0;
        pq.push({0,{0,0}});
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(row == n-1 and col == m-1) return diff;
            
            for(int i = 0;i<4;i++)
            {
               int nrow = row + delrow[i];
               int ncol = col + delcol[i];
               
               if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m)
               {
                   int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]),diff);
                   
                   if(newEffort < dis[nrow][ncol])
                   {
                       dis[nrow][ncol] = newEffort;
                       pq.push({dis[nrow][ncol],{nrow,ncol}});
                   }
               }
            }
        }
        return 0;
    }
};