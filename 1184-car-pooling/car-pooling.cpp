class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>mp(1001,0);

        for(auto &v:trips)
        {
            int start = v[1];
            int end = v[2];
            mp[start] += v[0];
            mp[end] -= v[0];
        }

        int sum = capacity;
        for(int i = 0;i<1001&&sum >= 0;i++)
        {
            sum -= mp[i];
        }
        return sum >= 0;
    }
};