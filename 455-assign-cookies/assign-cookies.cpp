class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(),s.rend());
        int n = g.size();
        int m = s.size();

        int total = 0;
        int curr = 0;

        for(int i = 0;i<n;i++)
        {
            if(curr < m && s[curr] >= g[i])
            {
                curr++;
                total++;
            }
        }
        return total;
    }
};