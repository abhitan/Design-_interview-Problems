class Solution {
public:

   void dfs(vector<vector<int>>& rooms,int src,vector<bool>&visited)
   {
       visited[src] = true;
       for(auto &node:rooms[src])
       {
           if(!visited[node])
           {
               dfs(rooms,node,visited);
           }
       }
   }



    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int V = rooms.size();
        vector<bool>visited(V,false);

        dfs(rooms,0,visited);

        for(bool x:visited)
        {
            if(x == false)
            return false;
        }
      return true;
    }
};