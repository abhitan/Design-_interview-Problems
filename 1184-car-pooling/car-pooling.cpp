class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>mp;
        for(auto &v:trips)
        {
            int start = v[1];
            int end = v[2];
            mp[start] += v[0];
            mp[end] -= v[0];
        }

        int sum = 0;
        for(auto &it:mp)
        {
            sum += it.second;
            if(sum > capacity)
            return false;
        }
        return true;
    }
};