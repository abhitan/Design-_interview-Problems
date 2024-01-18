class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        int res = 0;
        int left = -1;
        int right = -1;

        for(auto &v:intervals)
        {
            if(v[0] > left && v[1] > right)
            {
                left = v[0];
                res++;
            }
            right = max(right,v[1]);
        }
        return res;
    }
};