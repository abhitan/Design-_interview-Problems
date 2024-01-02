class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi = INT_MIN;
        for(auto it:nums)
        {
            mp[it]++;
        }

     for(auto it:mp) maxi = max(maxi,it.second);
        vector<vector<int>>ans(maxi);
        for(auto &it:mp)
        {
            int x = it.second;
            int val = it.first;
            int i = 0;

            while(x != 0)
            {
                ans[i].push_back(val);
                x--;
                i++;
            }
        }
        return ans;
    }
};