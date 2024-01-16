class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i = 0;i<points.size();i++)
        {
            int dist = (points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            if(pq.size() < k)
            {
                pq.push({dist,{points[i][0],points[i][1]}});
            }
            else
            {
                if(pq.top().first >dist)
                {
                    pq.pop();
                    pq.push({dist,{points[i][0],points[i][1]}});
                }
            }
        }

        vector<vector<int>>ans;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            ans.push_back({it.second.first,it.second.second});
        }
        return ans;
    }
};